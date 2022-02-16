#include "flowerbed.h"

flowerbed::flowerbed(int flowerId,
    std::string flowerShape,
    std::list<std::string> flowers){
    assert(flowerId > 0);
    assert(flowerShape == "circle" ||
        flowerShape == "square" ||
        flowerShape == "rhombus");
    assert(!flowers.empty());
    id = flowerId;
    if (flowerShape == "circle")
        shape = CIRCLE;
    if (flowerShape == "square")
        shape = SQUARE;
    if (flowerShape == "rhombus")
        shape = RHOMBUS;
    this->flowers = flowers;
}
int flowerbed::getId(){ return id; }
flowerbed::shapes flowerbed::getShape(){ return shape; }
std::string flowerbed::strShape(){
    std::string shapeToString;
    switch (shape){
    case 0:
        shapeToString = "circle";
        break;
    case 1:
        shapeToString = "square";
        break;
    case 2:
        shapeToString = "rhombus";
        break;
    default:
        break;
    }
    return shapeToString;
}
std::list<std::string> flowerbed::getFlowers(){ return flowers; }
std::string flowerbed::strFlowers(){
    std::string flowerStr = "";
    for (std::string str : flowers)
        flowerStr += str + ' ';
    return flowerStr;
}
void flowerbed::addFlower(std::string flower){ flowers.push_back(flower); }
std::list<flowerbed> flowerbed::getFlowerbedsFromFile(const std::string& file_path){
    std::ifstream file(file_path);
    std::list<flowerbed> inputFlowerbeds;
    std::string flowerbeds = "";
    if (file.is_open()){
        while (getline(file, flowerbeds)){
            std::vector<int> spaces;
            for (int i = 0; i < flowerbeds.size(); ++i){
                if (flowerbeds[i] == ' ')
                    spaces.push_back(i);
            }
            std::list<std::string> flowers;
            for (int i = spaces.size(); i > 1; --i)
                flowers.push_front(flowerbeds.substr(spaces[i - 1] + 1, spaces[i] - spaces[i - 1] - 1));
            flowerbed object(std::stoi(flowerbeds.substr(0, spaces[0])), flowerbeds.substr(spaces[0] + 1, spaces[1] - spaces[0] - 1), flowers);
            inputFlowerbeds.push_back(object);
        }
    }
    return inputFlowerbeds;
}
void flowerbed::sortByShape(std::list<flowerbed>& container){
    std::list<flowerbed> sortedContainer;
    for (flowerbed fb : container){
        if (fb.getShape() == 0)
            sortedContainer.push_front(fb);
        if (fb.getShape() == 1)
            sortedContainer.push_back(fb);
    }
    for (flowerbed fb : container){
        if (fb.getShape() == 2)
            sortedContainer.push_back(fb);
    }
    container = sortedContainer;
}
std::multimap<flowerbed::shapes, flowerbed> flowerbed::listToMultimap(std::list<flowerbed>& container){
    std::multimap<flowerbed::shapes, flowerbed> newContainer;
    for (flowerbed fb : container)
        newContainer.insert(std::pair<flowerbed::shapes, flowerbed>(fb.getShape(), fb));
    return newContainer;
}
void flowerbed::differentShapes(std::multimap<flowerbed::shapes, flowerbed>& container){
    std::multimap<flowerbed::shapes, flowerbed>::iterator it;
    if (container.count(CIRCLE) > 0)
        std::cout << "circle" << std::endl;
    if (container.count(SQUARE) > 0)
        std::cout << "square" << std::endl;
    if (container.count(RHOMBUS) > 0)
        std::cout << "rhombus" << std::endl;
}
void flowerbed::flowersOnFlowerbed(flowerbed& object){ std::cout << object.strFlowers() << std::endl; }
void flowerbed::allKindsOfFlowers(std::multimap<flowerbed::shapes, flowerbed>& container){
    std::multimap<flowerbed::shapes, flowerbed>::iterator it;
    std::list<std::string> allFlowers;
    for (it = container.begin(); it != container.end(); ++it){
        for (std::string str : it->second.flowers)
            allFlowers.push_back(str);
    }
    allFlowers.sort();
    allFlowers.unique();
    for (std::string str : allFlowers)
        std::cout << str << std::endl;
}
void flowerbed::sameFlowerbeds(std::multimap<flowerbed::shapes, flowerbed>& container){
    std::multimap<flowerbed::shapes, flowerbed>::iterator it1;
    std::multimap<flowerbed::shapes, flowerbed>::iterator it2;
    std::list<flowerbed> sameFlowerbeds;
    std::list<flowerbed> outedFlowerbeds;
    for (it1 = container.begin(); it1 != container.end(); ++it1){
        sameFlowerbeds = { it1->second };
        for (it2 = container.begin(); it2 != container.end(); ++it2){
            bool flag = true;
            if (it2->second == it1->second){
                for (flowerbed fb : outedFlowerbeds){
                    if (fb == it2->second){
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    sameFlowerbeds.push_back(it2->second);
            }
        }
        if (sameFlowerbeds.size() > 2){
            sameFlowerbeds.pop_front();
            for (flowerbed fb : sameFlowerbeds){
                outedFlowerbeds.push_back(sameFlowerbeds.front());
                std::cout << fb;
            }
        }
    }
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
std::list<flowerbed> flowerbed::flowerbedsByNumber(std::multimap<flowerbed::shapes, flowerbed>& container, unsigned int numnberOfFlowers){
    std::list<flowerbed> flowerbeds;
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
    throw std::runtime_error("No cuch flowerbeds");
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
std::list<flowerbed> flowerbed::flowerbedsWithoutFlower(std::multimap<flowerbed::shapes, flowerbed>& container, const std::string& flower){
    std::list<flowerbed> flowerbedWithoutFlower;
    std::multimap<flowerbed::shapes, flowerbed>::iterator it;
    for (it = container.begin(); it != container.end(); ++it){
        bool flag = true;
        for (std::string str : it->second.flowers){
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
int flowerbed::operator()(std::multimap<flowerbed::shapes, flowerbed>& container){
    static int answer = 0;
    std::function add{
        [](flowerbed& fb){answer += fb.getFlowers().size();}
    };
    std::vector<flowerbed> flowerbeds;
    std::multimap<flowerbed::shapes, flowerbed>::iterator it;
    for (it = container.begin(); it != container.end(); ++it){
        if (it->first == 0)
            flowerbeds.push_back(it->second);
    }
    std::for_each(flowerbeds.begin(), flowerbeds.end(), add);
    return answer;
};
std::list<flowerbed> flowerbed::operator()(std::multimap<flowerbed::shapes, flowerbed>& container,
    int numberOfFlowers){
    static std::list<flowerbed> resultFlowerbeds;
    std::function isSuitalbe{
        [numberOfFlowers](flowerbed& fb){
            if (fb.getFlowers().size() == numberOfFlowers)
                resultFlowerbeds.push_back(fb);
        }
    };
    std::list<flowerbed> flowerbeds;
    std::multimap<flowerbed::shapes, flowerbed>::iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        flowerbeds.push_back(it->second);
    std::for_each(flowerbeds.begin(), flowerbeds.end(), isSuitalbe);
    return resultFlowerbeds;
}
std::list<flowerbed> flowerbed::operator()(std::multimap<flowerbed::shapes, flowerbed>& container,
    const std::string& shape){
    static std::list<flowerbed> resultFlowerbeds;
    std::function isSuitalbe{
        [shape](flowerbed& fb){
            if (fb.strShape() == shape)
                resultFlowerbeds.push_back(fb);
        }
    };
    std::list<flowerbed> flowerbeds;
    std::multimap<flowerbed::shapes, flowerbed>::iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        flowerbeds.push_back(it->second);
    std::for_each(flowerbeds.begin(), flowerbeds.end(), isSuitalbe);
    return resultFlowerbeds;
}
bool operator == (flowerbed& first, flowerbed& second){
    return first.getFlowers() == second.getFlowers() && first.getShape() == second.getShape();
}
std::ostream& operator<< (std::ostream& out, flowerbed& flowerbed){
    out << "flowerbed id " << flowerbed.getId() << std::endl
        << "flowerbed shape " << flowerbed.strShape() << std::endl
        << "flowers in flowerbed: " << flowerbed.strFlowers() << std::endl;
    return out;
}