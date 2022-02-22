#include "functions.h"

void fileToList(){
    std::ifstream file("input.txt");
    std::list<std::string> inputList;
    std::string str;
    std::copy(
        std::istream_iterator<std::string>(file),
        std::istream_iterator<std::string>(),
        std::back_inserter(inputList));
    printL(inputList);
}
void printList(){
    std::list<std::string> inputList = { "string", "str", "function","solution" };
    std::copy(inputList.begin(), inputList.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
}
void copyContainer(){
    std::list<int> firstContainer = { 1,2,3,4 };
    std::vector<int> secondcontainer = { 0,0,0,0 };
    std::copy(firstContainer.begin(), firstContainer.end(), secondcontainer.begin());
    printV(secondcontainer);
}
void sortContainer(){
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
void findByLetter(){
    char letter = 's';
    std::list<std::string> container = { "string", "str", "function","solution" };
    std::function equalFirstLetter{
        [letter] (const std::string word){return word[0] == letter;}
    };
    std::list<std::string> answer1;
    std::list<std::string> answer2;
    container.sort();
    std::list<std::string>::iterator it1 = std::find_if(container.begin(), container.end(), equalFirstLetter);
    std::list<std::string>::iterator it2 = std::find_if_not(it1, container.end(), equalFirstLetter);
    std::copy(it1, it2, std::back_inserter(answer1));
    printL(answer1);
    std::list<std::string>::iterator it3 = std::find_if(container.begin(), container.end(), equal(letter));
    std::list<std::string>::iterator it4 = std::find_if_not(it3, container.end(), equal(letter));
    std::copy(it3, it4, std::back_inserter(answer2));
    printL(answer2);
}
void deleteByLetter(){
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
void countByLetter(){
    char letter = 's';
    std::list<std::string> container = { "string", "str", "function", "function", "solution" };
    std::function containsLetter{
        [letter] (const std::string& word){return word.find(letter) != std::string::npos;}
    };
    std::cout << std::count_if(container.begin(), container.end(), containsLetter) << std::endl;
}
void revercePrint(){
    std::function reverce{
        [](std::list<std::string>& container){
            container.reverse();
            std::cout << std::endl << "new container" << std::endl;
            for (std::string str : container)
                std::cout << str << std::endl;
        }
    };
    std::list<std::string> container = { "string", "str", "function","solution" };
    reverce(container);
}
void printDifferentWords(){
    std::ifstream file("input.txt");
    std::string str;
    std::list<std::string> words;
    while (file >> str)
        words.push_back(str);
    words.sort();
    words.unique();
    std::cout << words.size() << std::endl;
    printL(words);
}
void countDifferentWords(){
    std::ifstream file("input.txt");
    std::string str;
    std::list<std::string> words;
    while (file >> str)
        words.push_back(str);
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
void sortClass(){
    element firstElement(1, 2, 3, 4);
    element secondElement(4, 3, 2, 1);
    element thirdElement(0, 1, 2, 3);
    element fourthElement(-1, 2, 2, 1);
    element fifthElement(0, 0, 0, 0);
    std::vector<element> elements = { firstElement, secondElement ,thirdElement, fourthElement ,fifthElement };
    container con(elements);
    con.print();
    con.sortByOneKey();
    std::cout << "sorted by one key" << std::endl;
    con.print();
    con.sortByTwoKeys();
    std::cout << "sorted by two keys" << std::endl;
    con.print();
    con.sortByThreeKeys();
    std::cout << "sorted by three keys" << std::endl;
    con.print();
}