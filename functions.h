#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <functional>
#include <fstream>
#include <iterator>
#include "class4.h"
#include "class5.h"
#include "class11.h"

template<typename T>
void printL(const std::list<T>& list){
    for (T part : list)
        std::cout << part << std::endl;
}
template<typename T>
void printV(const std::vector<T>& vector){
    for (T part : vector)
        std::cout << part << std::endl;
}
void fileToList();
void printList();
void copyContainer();
void sortContainer();
void findByLetter();
void deleteByLetter();
void countByLetter();
void revercePrint();
void printDifferentWords();
void countDifferentWords();
void sortClass();