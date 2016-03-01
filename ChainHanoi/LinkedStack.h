#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
using namespace std;
//������һ��ģ���� 
template <class T> class LinkedStack;
//����ڵ��� 
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
//��������ʽջ 
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
//����������������нڵ� 
template<class T>
LinkedStack<T>::~LinkedStack(){
	Node<T>*next;
	while(top){
		next=top->link;
		delete top;
		top=next;
		
	}
} 
//�ж��Ƿ��� 
template<class T>
bool LinkedStack<T>::isFull()const{
  try{Node<T>*p=new Node<T>;
    delete p;
    return false;

  }
  catch(NoMem &nomem){return true;}
}
//����ջ��Ԫ�� 
template<class T>
T LinkedStack<T>::Top()const{
	if(isEmpty()) return;
	return top->data;
}
//����һ��Ԫ�� 
template<class T>
LinkedStack<T>&LinkedStack<T>::Add(const T&x) //��������ΪLinkedStack<T>����Ϊ�ǳ�Ա���� ������Ҫ::��ʹ��& ��Ϊ���÷��� �������Ӹ��� 
{
	Node<T>*p=new Node<T>;
	p->data=x;
	p->link=top;            //pָ��ԭ����ջ��Ԫ��  
	top=p;                  //�������ӵ�p����Ϊջ��Ԫ��top  
	return*this;
}
//ɾ��һ��Ԫ�� 
template<class T>
LinkedStack<T>&LinkedStack<T>::Delete( T&x){
	if(isEmpty()) cout<<"error";
	x=top->data;
	Node<T>*p=top;
	top=top->link;    //ָ��ջ������ĵ�һ��Ԫ�� 
	delete p;         //�����¡�������ϣ�ɾ��ջ��Ԫ��  
	return *this;
}


#endif






