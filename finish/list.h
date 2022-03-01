#include <iostream>

template <typename T>
struct node {
    T value;
    node* next;
};

template <class T>
class list{
protected:
    node<T>* head;
    int size;
public:
    ~list(){
        node<T>* temp = head;
        for (int i = 0; i < size - 1; ++i)
            delete temp->next;
        delete head;
    }
    list() : size(0){ head = nullptr; }
    void push(T data){
        node<T>* newHead = new(node<T>);
        newHead->next = nullptr;
        newHead->value = data;
        node<T>* temp = head;
        if (head == nullptr){
            head = newHead;
            ++size;
            return;
        }
        for (int i = 0; i < size - 1; ++i)
            temp = temp->next;
        temp->next = newHead;
        ++size;
    };
    void remove(T data){
        if (head->value == data){
            head = head->next;
            --size;
            return;
        }
        node<T>* temp = head;
        for (int i = 0; i < size; ++i){
            if (temp->next->value == data){
                delete temp->next;
                --size;
                return;
            }
            temp = temp->next;
        }
    }
    void print(std::ostream& out){
        node<T>* temp = head;
        for (int i = 0; i < size; ++i){
            out << temp->value << std::endl;
            temp = temp->next;
        }
    }
    bool isEmpty(){ return head == nullptr; }
    T topValue(){ return head->value; }
};
template<class T>
class sortedList : public list<T>{
public:
    void push(T data){
        node<T>* newHead = new(node<T>);
        newHead->next = nullptr;
        newHead->value = data;
        if (list<T>::head == nullptr){
            list<T>::head = newHead;
            ++list<T>::size;
            return;
        }
        node<T>* temp1 = list<T>::head;
        node<T>* temp2 = list<T>::head;
        for (int i = 0; i < list<T>::size; ++i){
            if (temp1->value < data){
                if (temp1->next == nullptr){
                    ++list<T>::size;
                    temp1->next = newHead;
                    return;
                }
                temp2 = temp1;
                temp1 = temp1->next;
            }
            else{
                if (temp1 == list<T>::head){
                    newHead->next = list<T>::head;
                    list<T>::head = newHead;
                    ++list<T>::size;
                    return;
                }
                temp2->next = newHead;
                newHead->next = temp1;
                ++list<T>::size;
                return;
            }
        }
    }
};