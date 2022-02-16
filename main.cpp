#include "functions.h"

int main(){
    std::function numberOfflowersOnCircleFlowerbedsLambda{
        [](std::multimap<flowerbed::shapes, flowerbed>& container){
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
        }
    };
    std::function findByNumberOfFlowersLambda{
        [](std::multimap<flowerbed::shapes, flowerbed>& container,
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
    };
    std::function findByShapeLambda{
        [](std::multimap<flowerbed::shapes, flowerbed>& container,
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
    };
    return 0;
}