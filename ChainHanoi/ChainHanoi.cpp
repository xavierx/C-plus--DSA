#include<iostream>
#include"LinkedStack.h"

using namespace std;

int sum=1; //ȫ�ֱ��������ڼƲ��� 

//��ŵ���� ���� �ƶ����� �� 3����  1 2 3   
class Hanoi{
	friend void TowersOfHanoi(int n);
	public:
		void TowersOfHanoi(int n,int x,int y,int z);
	private:
		LinkedStack<int>*S[4]; //Ϊ�˱�� 1 2 3 ������Ҫ4�� 
};
//�ݹ�  n������ ��x��y ���� z  
void Hanoi::TowersOfHanoi(int n,int x,int y,int z){
	int d;
	if(n>0){
		TowersOfHanoi(n-1,x,z,y); //�Ƚ�n-1�����Ӵ�x�Ƶ�z����y
		S[x]->Delete(d);          //��x�е����������ƶ���y�� 
		S[y]->Add(d);
        cout<<sum++<<": "<<x <<"--->"<<y <<"  "<<endl; //���������ʾ���� 
		TowersOfHanoi(n-1,z,y,x);  //�ٽ�n-1�����Ӵ�zһ����y����x ����ʱx�е����ĵ����Ѿ��ƶ�����y�� 
	}
	
}
//����ŵ��ת��Ϊ����ջ����������  nΪ������Ŀ  
void TowersOfHanoi(int n){
	Hanoi X;
	X.S[1]=new 	LinkedStack<int>;
    X.S[2]=new 	LinkedStack<int>;
    X.S[3]=new 	LinkedStack<int>;
    
    for(int d=n;d>0;d--){   //�����ӣ����ݣ���������ջ����  
    	X.S[1]->Add(d);   //�Ӵ�С ��n������ѹ��ջ��  
    }
    
    X.TowersOfHanoi(n,1,2,3); //��n������ ����1Ų����2 ������3 
}

int main(){
	TowersOfHanoi(8);   //���ú���ǰ���ü����ͣ������� 
	
	return 0;
}
