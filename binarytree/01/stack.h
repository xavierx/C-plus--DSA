#include<iostream>
#include<string>
using namespace std;
#define SIZE 100
 
#ifndef    STACK_H
#define    STACK_H
 
template <typename T>
class Stack
{
private:
         T array[SIZE];
         int count;
public:
         Stack();
         bool empty()const;
         void push(const T & element);
         void pop();
         T top();
};
 
template <typename T>
Stack<T>::Stack()
{
         count=-1;
}
 
 
template <typename T>
bool Stack<T>::empty() const
{
         return(count==-1);
}
 
 
template <typename T>
void Stack<T>::push(const T & element)
{
         count++;
         array[count]=element;
}
 
 
template <typename T>
void Stack<T>::pop()
{
         if(empty())
                   cout<<"error:the stack is empty"<<endl;
         else
                   count--;
        
}
 
 
template <typename T>
T Stack<T>::top()
{
         return array[count];
}
 
#endif
