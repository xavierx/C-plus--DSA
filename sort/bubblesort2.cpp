#include<iostream>
#include <cstdlib>
#include <ctime>
#include"swap.h"
using namespace std;

/*
void bubble(int a[],int n){  //һ��ð�� 
	for(int i=0;i<n-1;i++)
	if(a[i]>a[i+1])
	swap(a[i],a[i+1]);
}
*/
//ð�������ȶ�����   ʱ�临�Ӷȣ���� n � n^2 
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
    cout<<"����������Ҫ�������С " ;
    cin>>n;         
    int a[n];                //��������Ҫ�������С 
    for ( int i = 0 ; i < n; i ++ )
     a[i]=rand() % 100000 ;    //����������� 
     
    cout<<"����֮ǰ���飺"; 
   	for(int i=0;i<n;i++)
	cout<<a[i]<<"\t";
	cout<<endl; 
	/* 
	start=clock();         //��ʼ��ʱ 
	for(int i=N;i>1;i--)   //���������ð������ 
	bubble(a,N);
	end=clock();         //������ʱ  
	*/
	start=clock(); 
	bubblesort(a,n);   //XXXXXX������Ϊʵ�ξͷ������� ����[]! 
	end=clock();
	dif=end-start;
	
	cout<<"����֮�����飺"; 
	for(int i=0;i<n;i++)
	cout<<a[i]<<"\t";
	
	cout<<endl<<dif/CLOCKS_PER_SEC<<endl;
	return 0;
}
