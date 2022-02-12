#include"functions.h"

std::ostream& operator<< (std::ostream& out, flowerbed& flowerbed){
    out << "flowerbed id " << flowerbed.getId() << std::endl
        << "flowerbed shape " << flowerbed.getShape() << std::endl
        << "flowers in flowerbed: " << flowerbed.getFlowers() << std::endl;
    return out;
}