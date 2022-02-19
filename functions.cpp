#include "functions.h"

void task1(){
    std::ifstream file("input.txt");
    std::list<std::string> inputList;
    std::string str;
    std::copy(
        std::istream_iterator<std::string>(file),
        std::istream_iterator<std::string>(),
        std::back_inserter(inputList));
    printL(inputList);
}
void task2(){
    std::list<std::string> inputList = { "string", "str", "function","solution" };
    std::copy(inputList.begin(), inputList.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
}
void task3(){
    std::list<int> firstContainer = { 1,2,3,4 };
    std::vector<int> secondcontainer = { 0,0,0,0 };
    std::copy(firstContainer.begin(), firstContainer.end(), secondcontainer.begin());
    printV(secondcontainer);
}
void task4(){
    std::function bigger{
        [](const point& first, const point& second){return first >= second;}
    };
    point A (1, 1);
    point B (-1, 2);
    point C (0, 3);
    std::list<point> points = { A, B, C, B ,A };
    printL(points);
    std::cout << std::endl;
    points.sort();
    printL(points);
    std::cout << std::endl;
    points.sort(bigger);
    printL(points);
}
void task5(){
    char letter = 's';
    std::list<std::string> container = { "string", "str", "function","solution" };
    std::function equalFirstLetter{
        [letter] (const std::string word){return word[0] == letter;}
    };
    container.sort();
    std::list<std::string>::iterator it1 = std::find_if(container.begin(), container.end(), equalFirstLetter);
    std::list<std::string>::iterator it2 = std::find_if_not(it1, container.end(), equalFirstLetter);
    printL(container);
    std::list<std::string>::iterator it3 = std::find_if(container.begin(), container.end(), equal(letter));
    std::list<std::string>::iterator it4 = std::find_if_not(it3, container.end(), equal(letter));
    printL(container);
}
void task6(){
    char letter = 's';
    std::list<std::string> container = { "string", "str", "function", "function", "function", "solution" };
    std::function equalFirstLetter{
        [letter] (const std::string& word){return word[0] == letter;}
    };
    container.sort();
    std::list<std::string>::iterator it1 = std::find_if(container.begin(), container.end(), equalFirstLetter);
    std::list<std::string>::iterator it2 = std::find_if_not(it1, container.end(), equalFirstLetter);
    container.erase(it1, it2);
    printL(container);
}
void task7(){
    char letter = 's';
    std::list<std::string> container = { "string", "str", "function", "function", "solution" };
    std::function containsLetter{
        [letter] (const std::string& word){return word.find(letter) != std::string::npos;}
    };
    std::cout << std::count_if(container.begin(), container.end(), containsLetter) << std::endl;
}
void task8(){
    std::function reverce{
        [](std::list<std::string>& container){
            container.reverse();
            std::cout << std::endl << "new container" << std::endl;
            for (std::string str : container)
                std::cout << str << std::endl;
        }
    };
    std::list<std::string> container = { "string", "str", "function","solution" };
    printL(container);
}
void task9(){
    std::ifstream file("input.txt");
    std::string str;
    std::list<std::string> words;
    std::function isEndOfWord{
        [](char& letter){return letter == ' ';}
    };
    while (file >> str){
        std::string word;
        for (int i = 0; i < str.size(); ++i){
            if (str[i] != ' ')
                word += str[i];

        }
        words.push_back(word);
    }
    words.sort();
    words.unique();
    std::cout << words.size() << std::endl;
    printL(words);
}
void task10(){
    std::ifstream file("input.txt");
    std::string str;
    std::list<std::string> words;
    while (file >> str){
        std::string word;
        for (int i = 0; i < str.size(); ++i){
            if (str[i] != ' ')
                word += str[i];
        }
        words.push_back(word);
    }
    std::function countWords{
        [words](const std::string& word){
            int counter = -1;
            for (std::string str : words){
                if (word == str)
                    ++counter;
            }
            std::cout << counter << std::endl;
        }
    };
    std::for_each(words.begin(), words.end(), countWords);
}
void task11(){

}