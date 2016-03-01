#include<iostream>
#include <cstdlib>
#include <ctime>
#include"swap.h"
using namespace std;
//�������� ���ȶ� �� � n^2 ��� nlogn 
void quicksort(int a[],int low,int high){
	
	 if(low >= high)   return;  //�����ж������Ѿ�����  
	 
	int key=a[low];
	int i=low,j=high;
	
	while(i<j){
	 while(i<j&&a[j]>=key) --j;
	 swap(a[i],a[j]);        //a[i]=a[j] 
	 while(i<j&&a[i]<=key) ++i;
	 swap(a[i],a[j]);        //a[j]=a[i] //Ҳ����  

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
    cout<<"����������Ҫ�������С " ;
    cin>>n;         
    int a[n];                //��������Ҫ�������С 
    for ( int i = 0 ; i < n; i ++ )
     a[i]=rand() %10000;    //����������� 
     
	 cout<<"����֮ǰ���飺"; 
   	for(int i=0;i<n;i++)
	cout<<a[i]<<"\t";
	cout<<endl; 
    
    start=clock(); 
    quicksort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
    end=clock();
	dif=end-start;
	
   cout<<"����֮�����飺"; 
	for(int i=0;i<n;i++)
	cout<<a[i]<<"\t";
	
	cout<<endl<<dif<<endl;
	return 0;
}
