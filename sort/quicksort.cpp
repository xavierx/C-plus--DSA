#include<iostream>
#include <cstdlib>
#include <ctime>
#include"swap.h"
using namespace std;
//快速排序： 不稳定 ； 最坏 n^2 最好 nlogn 
void quicksort(int a[],int low,int high){
	
	 if(low >= high)   return;  //！！判断排序已经结束  
	 
	int key=a[low];
	int i=low,j=high;
	
	while(i<j){
	 while(i<j&&a[j]>=key) --j;
	 swap(a[i],a[j]);        //a[i]=a[j] 
	 while(i<j&&a[i]<=key) ++i;
	 swap(a[i],a[j]);        //a[j]=a[i] //也可行  

	}
	
	quicksort(a,low,i-1);
	quicksort(a,i+1,high);
	
}

int main()
{
    srand ( time (NULL) );
	clock_t start,end;
	double dif;
    int n;
    cout<<"请输入你想要的数组大小 " ;
    cin>>n;         
    int a[n];                //输入你想要的数组大小 
    for ( int i = 0 ; i < n; i ++ )
     a[i]=rand() %10000;    //生成随机数组 
     
	 cout<<"排序之前数组："; 
   	for(int i=0;i<n;i++)
	cout<<a[i]<<"\t";
	cout<<endl; 
    
    start=clock(); 
    quicksort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
    end=clock();
	dif=end-start;
	
   cout<<"排序之后数组："; 
	for(int i=0;i<n;i++)
	cout<<a[i]<<"\t";
	
	cout<<endl<<dif<<endl;
	return 0;
}
