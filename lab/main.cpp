#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cassert>
#include <numeric>

class initial{
private:
    char letter;
    initial() = default;
public:
    initial(char inputLetter) : letter(inputLetter){}
    ~initial() = default;
    bool operator()(const std::string& word){ return word[0] == letter; }
};
class initialNot{
private:
    char letter;
    initialNot() = default;
public:
    initialNot(char inputLetter) : letter(inputLetter){}
    ~initialNot() = default;
    bool operator()(const std::string& word){ return word[0] != letter; }
};
class myStr{
private:
    std::string myString;
    myStr() = default;
public:
    myStr(std::string inputStr) : myString(inputStr){}
    ~myStr() = default;
    std::string getStr(){ return myString; }
    int getSize(){ return myString.size(); }
    friend bool operator== (const myStr& obj, const std::string& str){
        return obj.myString == str;
    }
};

void printByLetter(std::list<std::string>& list, char letter){
    std::function equal{
        [letter](const std::string& str){return str[0] == letter;}
    };
    std::list<std::string>::iterator it1 = std::find_if(list.begin(), list.end(), equal);
    std::list<std::string>::iterator it2 = std::find_if_not(it1, list.end(), equal);
    std::cout << std::endl;
    for (it1; it1 != it2; ++it1)
        std::cout << *it1 << std::endl;
    std::cout << std::endl;

}
void deleteByLetter(std::list<std::string>& list, char letter){
    std::list<std::string>::iterator it1 = std::find_if(list.begin(), list.end(), initial('g'));
    std::list<std::string>::iterator it2 = std::find_if(it1, list.end(), initialNot('g'));
    list.erase(it1, it2);
    std::cout << std::endl;
    for (std::string str : list)
        std::cout << str << std::endl;
    std::cout << std::endl;
}
void countEqual(const std::list<double>& list, double number){
    std::cout << std::count(list.begin(), list.end(), number) << std::endl;
}
void countBetween(const std::list<double>& list, double min, double max){
    assert(min <= max);
    std::function isBetween{
        [min, max](const double& a){
            return a >= min && a <= max;
        }
    };
    std::cout << std::count_if(list.begin(), list.end(), isBetween) << std::endl;
}
void findMeridian(const std::list<double> list){
    double sum = std::accumulate(list.begin(), list.end(), 0);
    std::cout << sum / list.size() << std::endl;
}
void countEqaul(const std::list<myStr>& list, const std::string& inputString){
    std::cout << std::count(list.begin(), list.end(), inputString) << std::endl;
}
void sizeIsBetween(const std::list<myStr>& list, int min, int max){
    assert(min <= max);
    std::function isBetween{
        [min, max](myStr obj){return obj.getSize() >= min && obj.getSize() <= max;}
    };
    std::cout << std::count_if(list.begin(), list.end(), isBetween) << std::endl;
}

int main(){
    std::list<std::string> strList;
    std::string inputStr;
    std::ifstream file("input.txt");
    while (file >> inputStr)
        strList.push_back(inputStr);
    strList.sort();
    for (std::string str : strList)
        std::cout << str << std::endl;
    printByLetter(strList, 'h');
    deleteByLetter(strList, 'g');
    std::ifstream newFile("input2.txt");
    std::string str;
    std::list<double> newInput;
    while (newFile >> str)
        newInput.push_back(std::stod(str));
    countEqual(newInput, 1);
    countBetween(newInput, 5, 7);
    findMeridian(newInput);
    myStr first("dfsf");
    myStr second("qwerty");
    myStr third("mn");
    myStr fourth("lkj");
    myStr fifth("1337");
    myStr six("i");
    std::list<myStr> mystrigs = { first, second, third, fourth, fifth, six };
    countEqaul(mystrigs, "qwerty");
    sizeIsBetween(mystrigs, 1, 3);
    return 0;
}