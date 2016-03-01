#include<iostream>
#include <cstdlib>
#include <ctime>
#include"swap.h"
using namespace std;
//选择排序：稳定  最好 最坏 ：n^2 
void selectionsort(int a[],int n){
	bool sorted=false;
	for(int size=n;!sorted&&(size>1);size--){
		int pos=0;
		sorted=true;
		for(int i=1;i<size;i++)
		if(a[pos]<=a[i]) pos=i;  //选出最大的 
		else sorted=false;
		swap(a[pos],a[size-1]);  //将最大的放在数组最后一个  
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
     a[i]=rand() % 1000 ;    //生成随机数组 
     
    cout<<"排序之前数组："; 
   	for(int i=0;i<n;i++)
	cout<<a[i]<<"\t";
	cout<<endl; 
	 
	start=clock();         //开始计时 
    selectionsort(a,n);
	end=clock();         //结束计时  
	
	dif=end-start;
	
	cout<<"排序之后数组："; 
	for(int i=0;i<n;i++)
	cout<<a[i]<<"\t";
	
	cout<<endl<<dif<<endl;
	return 0;
}
