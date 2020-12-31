#include <iostream>
#include <list>

using namespace std;

template <class T>
class Queue{
private:
    list<T> data;
public:
    void enqueue(T val){data.push_back(val);}
    T top(){return data.front();}
    T dequeue(){T topVal = top(); data.pop_front(); return topVal;}
    bool isEmpty(){return data.size() == 0;}
    int size(){return data.size();}
    void clear(){data.clear();}
};


template <class T>
class Stack{
private:
    list<T> data;
public:
    void push(T value){data.push_front(value);}
    T top(){return data.front();}
    T pop(){T topVal = top(); data.pop_front(); return topVal;}
    bool isEmpty(){return data.size() == 0;}
    int size(){return data.size();}
    void clear(){data.clear();}
};

int main(){
    Stack<int> test;

    test.push(4);
    test.push(100);
    test.push(11);

    cout<<"size is: "<<test.size()<<endl;
    cout<<"top: "<<test.top()<<endl;
    cout<<"pop: "<<test.pop()<<endl;
    cout<<"is empty?: "<<test.isEmpty()<<endl;
    cout<<"size is: "<<test.size();
    cout<<endl<<endl;
    cout<<"top: "<<test.top()<<endl;
    cout<<"pop: "<<test.pop()<<endl;
    cout<<"is empty?: "<<test.isEmpty()<<endl;
    cout<<"size is: "<<test.size();
    cout<<endl<<endl;
    cout<<"top: "<<test.top()<<endl;
    cout<<"pop: "<<test.pop()<<endl;
    cout<<"is empty?: "<<test.isEmpty()<<endl;
    cout<<"size is: "<<test.size();
    cout<<endl<<endl;

    cout<<"Queue test"<<endl<<endl;
    Queue<int> testQ;

    testQ.enqueue(4);
    testQ.enqueue(100);
    testQ.enqueue(11);

    cout<<"size is: "<<testQ.size()<<endl;
    cout<<"top: "<<testQ.top()<<endl;
    cout<<"pop: "<<testQ.dequeue()<<endl;
    cout<<"is empty?: "<<testQ.isEmpty()<<endl;
    cout<<"size is: "<<testQ.size();
    cout<<endl<<endl;
    cout<<"top: "<<testQ.top()<<endl;
    cout<<"pop: "<<testQ.dequeue()<<endl;
    cout<<"is empty?: "<<testQ.isEmpty()<<endl;
    cout<<"size is: "<<testQ.size();
    cout<<endl<<endl;
    cout<<"top: "<<testQ.top()<<endl;
    cout<<"pop: "<<testQ.dequeue()<<endl;
    cout<<"is empty?: "<<testQ.isEmpty()<<endl;
    cout<<"size is: "<<testQ.size();
    cout<<endl<<endl;

    return 0;
}



