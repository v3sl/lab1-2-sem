#ifndef LAB
#define LAB

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <map>
#include <vector>
#include <functional>
#include<cassert>

class flowerbed {
public:
    enum shapes {
        CIRCLE,
        SQUARE,
        RHOMBUS
    };
    flowerbed(int flowerId, std::string flowerShape, std::list<std::string>);
    ~flowerbed() = default;
    int getId();
    shapes getShape();
    std::string strShape();
    std::list<std::string> getFlowers();
    std::string strFlowers();
    void addFlower(std::string flower);
    static std::list<flowerbed>getFlowerbedsFromFile(const std::string& file_path);
    static void sortByShape(std::list<flowerbed>& container);
    static std::multimap<flowerbed::shapes, flowerbed> listToMultimap(std::list<flowerbed>& container);
    static void differentShapes(std::multimap<flowerbed::shapes, flowerbed>& container);
    static void flowersOnFlowerbed(flowerbed& object);
    static void allKindsOfFlowers(std::multimap<flowerbed::shapes, flowerbed>& container);
    static void sameFlowerbeds(std::multimap<flowerbed::shapes, flowerbed>& container);
    static flowerbed flowersMax(std::multimap<flowerbed::shapes, flowerbed>& container);
    static std::list<flowerbed> flowerbedsByNumber(std::multimap<flowerbed::shapes, flowerbed>& container, unsigned int numnberOfFlowers);
    static flowerbed oneKindFlowerbeds(std::multimap<flowerbed::shapes, flowerbed>& container);
    static flowerbed maxKind(std::multimap<flowerbed::shapes, flowerbed>& container);
    static std::list<flowerbed> flowerbedsWithoutFlower(std::multimap<flowerbed::shapes, flowerbed>& container, const std::string& flower);
    int operator() (std::multimap<flowerbed::shapes, flowerbed>& container);
    std::list<flowerbed> operator() (std::multimap<flowerbed::shapes, flowerbed>& container,
        int numberOfFlowers);
    std::list<flowerbed> operator() (std::multimap<flowerbed::shapes, flowerbed>& container,
        const std::string& shape);
private:
    int id;
    shapes shape;
    std::list<std::string> flowers;
    flowerbed() = default;
};
bool operator == (flowerbed& first, flowerbed& second);
std::ostream& operator<<(std::ostream& out, flowerbed& flowerbed);
#endif 