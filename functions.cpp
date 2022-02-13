#include"functions.h"

std::ostream& operator<< (std::ostream& out, flowerbed& flowerbed){
    out << "flowerbed id " << flowerbed.getId() << std::endl
        << "flowerbed shape " << flowerbed.getShape() << std::endl
        << "flowers in flowerbed: " << flowerbed.getFlowers() << std::endl;
    return out;
}
int numberOfflowersOnCircleFlowerbeds(std::multimap<flowerbed::shapes,
    flowerbed>& container){
    int answer = 0;
    std::multimap<flowerbed::shapes, flowerbed>::iterator it;
    for (it = container.begin(); it != container.end(); ++it){
        if (it->first == 0)
            answer += it->second.flowers.size();
    }
    return answer;
}
void deleteFlower(std::multimap<flowerbed::shapes, flowerbed>& container,
    std::string flower){
    std::multimap<flowerbed::shapes, flowerbed>::iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        it->second.flowers.remove(flower);
}
std::list<flowerbed>findByNumberOfFlowers(std::multimap<flowerbed::shapes, flowerbed>& container,
    int numberOfFlowers){
    std::list<flowerbed> answer;
    std::multimap<flowerbed::shapes, flowerbed>::iterator it;
    for (it = container.begin(); it != container.end(); ++it){
        if (it->second.flowers.size() == numberOfFlowers)
            answer.push_back(it->second);
    }
    return answer;
}
std::list<flowerbed>findByShape(std::multimap<flowerbed::shapes, flowerbed>& container,
    const std::string& shape){
    std::function convert{
        [](const std::string& strShape){
            if (strShape == "circle")
                return 0;
            if (strShape == "square")
                return 1;
            return 2;
        }
    };
    std::list<flowerbed> answer;
    std::multimap<flowerbed::shapes, flowerbed>::iterator it;
    for (it = container.begin(); it != container.end(); ++it){
        if (it->first == convert(shape))
            answer.push_back(it->second);
    }
    return answer;
}
void lambdas(){

}