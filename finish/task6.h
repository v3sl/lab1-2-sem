#include "stack.h"
#include <vector>

bool isOperation(char ch){
    return ch == 'a' || ch == 'i';
}
int calculate(int firstVal, int secondVal, char operation){
    if (operation == 'i'){
        if (firstVal < secondVal)
            return firstVal;
        else
            return secondVal;
    }
    else{
        if (firstVal > secondVal)
            return firstVal;
    }
    return secondVal;
}

int task6(std::string input){
    stack<int> result;
    stack<char> operations;
    for (int i = 0; i < input.size(); ++i){
        if (isOperation(input[i])){
            operations.pushBack(input[i]);
        }
        else{
            std::string temp = "";
            while (!isOperation(input[i]) && input[i] != ')' && input[i] != '(' && i != input.size() && input[i] != ','){
                temp += input[i];
                ++i;
            }
            if (temp.size() > 0)
                result.pushBack(std::stoi(temp));
        }
    }
    while (!operations.isEmpty()){
        int second = result.top();
        result.pop();
        int first = result.top();
        result.pop();
        result.pushBack(calculate(first, second, operations.top()));
        operations.pop();
    }
    return result.top();
}