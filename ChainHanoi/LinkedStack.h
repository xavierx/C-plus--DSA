#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
using namespace std;
//先声明一个模板类 
template <class T> class LinkedStack;
//定义节点类 
template <class T>
class Node{
	friend LinkedStack<T>;
	
	private:
		T data;
		Node<T>*link;
};

class NoMem
{
 public:
      NoMem() {}
};
//定义链表式栈 
template<class T>
class LinkedStack{
	public:
		LinkedStack(){top=0;}
		~LinkedStack();
		bool isEmpty()const{return top==0;};
		bool isFull()const;
		T Top()const;
		LinkedStack<T>&Add(const T&x);
        LinkedStack<T>&Delete( T&x);	
	private:
	   Node<T>*top;	
};
//析构函数，清空所有节点 
template<class T>
LinkedStack<T>::~LinkedStack(){
	Node<T>*next;
	while(top){
		next=top->link;
		delete top;
		top=next;
		
	}
} 
//判断是否满 
template<class T>
bool LinkedStack<T>::isFull()const{
  try{Node<T>*p=new Node<T>;
    delete p;
    return false;

  }
  catch(NoMem &nomem){return true;}
}
//返回栈顶元素 
template<class T>
T LinkedStack<T>::Top()const{
	if(isEmpty()) return;
	return top->data;
}
//增加一个元素 
template<class T>
LinkedStack<T>&LinkedStack<T>::Add(const T&x) //返回类型为LinkedStack<T>。因为是成员函数 所以需要::。使用& 作为引用返回 不会增加副本 
{
	Node<T>*p=new Node<T>;
	p->data=x;
	p->link=top;            //p指向原来的栈顶元素  
	top=p;                  //将新增加的p，作为栈顶元素top  
	return*this;
}
//删除一个元素 
template<class T>
LinkedStack<T>&LinkedStack<T>::Delete( T&x){
	if(isEmpty()) cout<<"error";
	x=top->data;
	Node<T>*p=top;
	top=top->link;    //指向栈顶下面的第一个元素 
	delete p;         //“后事”交代完毕，删除栈顶元素  
	return *this;
}


#endif






