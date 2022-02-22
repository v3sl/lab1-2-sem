class equal{
private:
    char letter;
public:
    equal(char cletter) : letter(cletter){};
    bool operator()(const std::string& word) const{ return word[0] == letter; };
};