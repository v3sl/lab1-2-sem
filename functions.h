#include"flowerbed.h" 
#include <algorithm>

int numberOfflowersOnCircleFlowerbeds(std::multimap<flowerbed::shapes, flowerbed>& container);
std::list<flowerbed>findByNumberOfFlowers(std::multimap<flowerbed::shapes, flowerbed>& container,
    int numberOfFlowers);
std::list<flowerbed>findByShape(std::multimap<flowerbed::shapes, flowerbed>& container,
    const std::string& shape);