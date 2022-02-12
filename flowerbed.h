#ifndef LAB
#define LAB

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <map>
#include <vector>
#include <functional>

class flowerbed {
public:
    int id;
    enum shapes {
        CIRCLE,
        SQUARE,
        RHOMBUS
    };
    shapes shape;
    std::list<std::string> flowers;
public:
    flowerbed(int flowerId, std::string flowerShape, std::list<std::string>);
    ~flowerbed() = default;
    void addFlower(std::string flower);
    int getId();
    shapes getShape();
    std::string getFlowers();
    static std::multimap<flowerbed::shapes, flowerbed> getFlowerbedsFromFile(const std::string& file_path);
    static flowerbed flowersMax(std::multimap<flowerbed::shapes, flowerbed>& container);
    static std::vector<flowerbed> flowerbedsByNumber(std::multimap<flowerbed::shapes, flowerbed>& container, unsigned int numnberOfFlowers);
    static flowerbed oneKindFlowerbeds(std::multimap<flowerbed::shapes, flowerbed>& container);
    static flowerbed maxKind(std::multimap<flowerbed::shapes, flowerbed>& container);
    static std::string sameFlower(std::multimap<flowerbed::shapes, flowerbed>& container);
    static std::list<flowerbed> flowerbedWithoutFlower(std::multimap<flowerbed::shapes, flowerbed>& container, const std::string& flower);
};

#endif 