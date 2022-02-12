#include "flowerbed.h"

flowerbed::flowerbed(int flowerId = 0, std::string flowerShape = 0, std::list<std::string> flowers = {}){
    id = flowerId;
    if (flowerShape == "circle")
        shape = CIRCLE;
    if (flowerShape == "square")
        shape = SQUARE;
    if (flowerShape == "rhombus")
        shape = RHOMBUS;
    this->flowers.swap(flowers);
}
void flowerbed::addFlower(std::string flower){
    flowers.push_back(flower);
}
int flowerbed::getId(){
    return id;
}
flowerbed::shapes flowerbed::getShape(){
    return shape;
}
std::string flowerbed::getFlowers(){
    std::string flowerStr = "";
    for (std::string str : flowers)
        flowerStr += str + ' ';
    return flowerStr;
}
std::multimap<flowerbed::shapes, flowerbed> flowerbed::getFlowerbedsFromFile(const std::string& file_path){
    std::ifstream file(file_path);
    std::multimap<flowerbed::shapes, flowerbed> inputFlowerbeds;
    std::string flowerbeds = "";
    if (file.is_open()){
        while (getline(file, flowerbeds)){
            std::vector<int> spaces;
            for (size_t i = 0; i < flowerbeds.size(); ++i){
                if (flowerbeds[i] == ' ')
                    spaces.push_back(i);
            }
            std::list<std::string> flowers;
            for (size_t i = spaces.size(); i > 1; --i)
                flowers.push_front(flowerbeds.substr(spaces[i - 1] + 1, spaces[i] - spaces[i - 1] - 1));
            flowerbed object(std::stoi(flowerbeds.substr(0, spaces[0])), flowerbeds.substr(spaces[0] + 1, spaces[1] - spaces[0] - 1), flowers);
            inputFlowerbeds.insert(std::pair<flowerbed::shapes, flowerbed>(object.getShape(), object));
        }
    }
    return inputFlowerbeds;
}
flowerbed flowerbed::flowersMax(std::multimap<flowerbed::shapes, flowerbed>& container){
    std::function more{
              [](flowerbed first, flowerbed second){return !(first.flowers.size() >= second.flowers.size());}
    };
    std::multimap<flowerbed::shapes, flowerbed>::iterator it;
    flowerbed flowerbedWithMaxFlowers = container.begin()->second;
    for (it = container.begin(); it != container.end(); ++it){
        if (more(flowerbedWithMaxFlowers, it->second))
            flowerbedWithMaxFlowers = it->second;
    }
    return flowerbedWithMaxFlowers;
}
std::vector<flowerbed> flowerbed::flowerbedsByNumber(std::multimap<flowerbed::shapes, flowerbed>& container, unsigned int numnberOfFlowers){
    std::vector<flowerbed> flowerbeds;
    std::multimap<flowerbed::shapes, flowerbed>::iterator it;
    for (it = container.begin(); it != container.end(); ++it){
        if (it->second.flowers.size() == numnberOfFlowers)
            flowerbeds.push_back(it->second);
    }
    return flowerbeds;
}
flowerbed flowerbed::oneKindFlowerbeds(std::multimap<flowerbed::shapes, flowerbed>& container){
    std::multimap<flowerbed::shapes, flowerbed>::iterator it;
    for (it = container.begin(); it != container.end(); ++it){
        bool flag = true;
        for (std::string str : it->second.flowers){
            if (str != it->second.flowers.front()){
                flag = false;
                break;
            }
        }
        if (flag)
            return it->second;
    }
    flowerbed noSuchFlowerbeds;
    return noSuchFlowerbeds;
}
flowerbed flowerbed::maxKind(std::multimap<flowerbed::shapes, flowerbed>& container){
    std::function maxKind{
        [](flowerbed object){
            std::vector<unsigned int> counters;
            for (std::string str1 : object.flowers){
                unsigned int counter = 0;
                for (std::string str2 : object.flowers){
                    if (str1 == str2)
                        ++counter;
                }
                counters.push_back(counter);
            }
            unsigned int max = counters[0];
            for (size_t i = 1; i < counters.size(); ++i){
                if (counters[i] >= max)
                    max = counters[i];
            }
            return max;
        }
    };
    std::multimap<flowerbed::shapes, flowerbed>::iterator it;
    flowerbed maxKindFlowerBed = container.begin()->second;
    for (it = container.begin(); it != container.end(); ++it){
        if (maxKind(it->second) >= maxKind(maxKindFlowerBed))
            maxKindFlowerBed = it->second;
    }
    return maxKindFlowerBed;
}
std::string flowerbed::sameFlower(std::multimap<flowerbed::shapes, flowerbed>& container){
    std::multimap<flowerbed::shapes, flowerbed>::iterator it1;
    std::multimap<std::string, flowerbed> allFlowers;
    for (it1 = container.begin(); it1 != container.end(); ++it1){
        for (std::string str : it1->second.flowers)
            allFlowers.insert(std::pair<std::string, flowerbed>(str, it1->second));
    }
    std::multimap<std::string, flowerbed> ::iterator it2;
    std::multimap<std::string, flowerbed> ::iterator it3;
    for (it2 = allFlowers.begin(); it2 != allFlowers.end(); ++it2){
        unsigned int counter = 1;
        for (it3 = allFlowers.begin(); it3 != allFlowers.end(); ++it3){
            if (it2->first == it3->first && it2->second.id != it3->second.id)
                ++counter;
        }
        if (counter == container.size())
            return it2->first + '\n';
    }
    return "\n";
}
std::list<flowerbed> flowerbed::flowerbedWithoutFlower(std::multimap<flowerbed::shapes, flowerbed>& container, const std::string& flower){
    std::list<flowerbed> flowerbedWithoutFlower;
    std::multimap<flowerbed::shapes, flowerbed>::iterator it;
    for (it = container.begin(); it != container.end(); ++it){
        bool flag = true;
        for (std::string str : it->second.flowers){
            std::cout << str << std::endl;
            if (str == flower){
                flag = false;
                break;
            }
        }
        if (flag)
            flowerbedWithoutFlower.push_back(it->second);
    }
    return flowerbedWithoutFlower;
}