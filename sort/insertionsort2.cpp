#include<iostream>
#include <cstdlib>
#include <ctime>
#include"swap.h"
using namespace std;
//插入排序 稳定： 最好 n 最坏 n^2 
void insertionsort (int a[],int n)
{
	for (int i=1;i<n;i++)
	{	
		int j,temp;
		temp=a[i];
		for (j=i-1;j>=0&&temp<a[j];j--)
        {
		    a[j+1]=a[j];
		}
		a[j+1]=temp;
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
    insertionsort(a,n);
	end=clock();         //结束计时  
	
	dif=end-start;
	
	cout<<"排序之后数组："; 
	for(int i=0;i<n;i++)
	cout<<a[i]<<"\t";
	
	cout<<endl<<dif/CLOCKS_PER_SEC<<endl;
	return 0;
}
