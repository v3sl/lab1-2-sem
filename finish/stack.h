#include "list.h"

template <class T>
class stack : public list<T>{
private:
    list<T> list;
public:
    void pushBack(T data){ list.push(data); }
    void pop(){ list.remove(list.topValue()); }
    bool isEmpty(){ return list.isEmpty(); }
    T top(){ return list.topValue(); }
};