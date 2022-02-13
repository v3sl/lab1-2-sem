#include"flowerbed.h" 

std::ostream& operator<<(std::ostream& out, flowerbed& flowerbed);
int numberOfflowersOnCircleFlowerbeds(std::multimap<flowerbed::shapes,
    flowerbed>& container);
void deleteFlower(std::multimap<flowerbed::shapes, flowerbed>& container,
    std::string flower);
std::list<flowerbed>findByNumberOfFlowers(std::multimap<flowerbed::shapes, flowerbed>& container,
    int numberOfFlowers);
std::list<flowerbed>findByShape(std::multimap<flowerbed::shapes, flowerbed>& container,
    const std::string& shape);
void lambdas();