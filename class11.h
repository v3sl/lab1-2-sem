class element{
protected:
    int value;
    int key1;
    int key2;
    int key3;
    element() = default;
public:
    int getKey1(){ return key1; }
    int getKey2(){ return key2; }
    int getKey3(){ return key3; }
    element(int inputValue, int inputKey1, int inputKey2, int inputKey3) : value(inputValue), key1(inputKey1), key2(inputKey2), key3(inputKey3){}
    ~element() = default;
    friend std::ostream& operator <<(std::ostream& out, const element& obj){
        out << "value: " << obj.value << std::endl
            << "key1: " << obj.key1 << std::endl
            << "key2: " << obj.key2 << std::endl
            << "key3: " << obj.key3 << std::endl << std::endl;
        return out;
    }
};
class container : protected element{
private:
    std::vector<element> elements;
    container() = default;
public:
    container(std::vector<element> inputElements) : elements(inputElements){}
    void print(){
        for (element el : elements)
            std::cout << el;
    }
    void sortByOneKey(){
        std::function sortByKey1{
            [](element& first, element& second){
                return first.getKey1() > second.getKey1();
            }
        };
        std::sort(elements.begin(), elements.end(), sortByKey1);
    }
    void sortByTwoKeys(){
        std::function sortByKey1Key2{
            [](element& first, element& second){
                return first.getKey1() + first.getKey2() > second.getKey1() + second.getKey2();
            }
        };
        std::sort(elements.begin(), elements.end(), sortByKey1Key2);
    }
    void sortByThreeKeys(){
        std::function sortByKey1Key2key3{
            [](element& first, element& second){
                return first.getKey1() + first.getKey2() + first.getKey3() >
                    second.getKey1() + second.getKey2() + second.getKey3();
            }
        };
        std::sort(elements.begin(), elements.end(), sortByKey1Key2key3);
    }
};