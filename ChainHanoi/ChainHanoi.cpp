#include<iostream>
#include"LinkedStack.h"

using namespace std;

int sum=1; //全局变量，用于计步数 

//汉诺塔类 包含 移动函数 和 3个塔  1 2 3   
class Hanoi{
	friend void TowersOfHanoi(int n);
	public:
		void TowersOfHanoi(int n,int x,int y,int z);
	private:
		LinkedStack<int>*S[4]; //为了编号 1 2 3 所以需要4个 
};
//递归  n个盘子 从x到y 借助 z  
void Hanoi::TowersOfHanoi(int n,int x,int y,int z){
	int d;
	if(n>0){
		TowersOfHanoi(n-1,x,z,y); //先将n-1个碟子从x移到z借助y
		S[x]->Delete(d);          //将x中的最大的盘子移动到y上 
		S[y]->Add(d);
        cout<<sum++<<": "<<x <<"--->"<<y <<"  "<<endl; //在输出中显示出来 
		TowersOfHanoi(n-1,z,y,x);  //再将n-1个碟子从z一定到y借助x （此时x中的最大的碟子已经移动到了y） 
	}
	
}
//将汉诺塔转化为链表栈的数据类型  n为碟子数目  
void TowersOfHanoi(int n){
	Hanoi X;
	X.S[1]=new 	LinkedStack<int>;
    X.S[2]=new 	LinkedStack<int>;
    X.S[3]=new 	LinkedStack<int>;
    
    for(int d=n;d>0;d--){   //将盘子（数据）放在塔（栈）上  
    	X.S[1]->Add(d);   //从大到小 将n个数据压入栈中  
    }
    
    X.TowersOfHanoi(n,1,2,3); //将n个碟子 从塔1挪到塔2 借助塔3 
}

int main(){
	TowersOfHanoi(8);   //调用函数前不用加类型！！！！ 
	
	return 0;
}
