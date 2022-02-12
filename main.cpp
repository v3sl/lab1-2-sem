#include "functions.h"

int main(){
    std::multimap<flowerbed::shapes, flowerbed> mp;
    mp = flowerbed::getFlowerbedsFromFile(std::string("input.txt"));
    return 0;
}