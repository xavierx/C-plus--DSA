#include<iostream>
#include <cstdlib>
#include <ctime>
#include"swap.h"
using namespace std;

/*
void bubble(int a[],int n){  //一次冒泡 
	for(int i=0;i<n-1;i++)
	if(a[i]>a[i+1])
	swap(a[i],a[i+1]);
}
*/
//冒泡排序：稳定排序   时间复杂度：最好 n 最坏 n^2 
void bubblesort (int a[],int n){
	for(bool sorted=false;sorted=!sorted;n--)
		for(int i=0;i<n;i++){
			if(a[i]>a[i+1]){
				swap(a[i],a[i+1]);
				sorted=false;
			}
		}
	
}
int main(){
	srand ( time (NULL) );
	clock_t start,end;
	double dif;
    int n;
    cout<<"请输入你想要的数组大小 " ;
    cin>>n;         
    int a[n];                //输入你想要的数组大小 
    for ( int i = 0 ; i < n; i ++ )
     a[i]=rand() % 100000 ;    //生成随机数组 
     
    cout<<"排序之前数组："; 
   	for(int i=0;i<n;i++)
	cout<<a[i]<<"\t";
	cout<<endl; 
	/* 
	start=clock();         //开始计时 
	for(int i=N;i>1;i--)   //对数组进行冒泡排序 
	bubble(a,N);
	end=clock();         //结束计时  
	*/
	start=clock(); 
	bubblesort(a,n);   //XXXXXX数组作为实参就放数组名 不加[]! 
	end=clock();
	dif=end-start;
	
	cout<<"排序之后数组："; 
	for(int i=0;i<n;i++)
	cout<<a[i]<<"\t";
	
	cout<<endl<<dif/CLOCKS_PER_SEC<<endl;
	return 0;
}
