#include<iostream>
#include <cstdlib>
#include <ctime>
#include"swap.h"
using namespace std;
//ѡ�������ȶ�  ��� � ��n^2 
void selectionsort(int a[],int n){
	bool sorted=false;
	for(int size=n;!sorted&&(size>1);size--){
		int pos=0;
		sorted=true;
		for(int i=1;i<size;i++)
		if(a[pos]<=a[i]) pos=i;  //ѡ������ 
		else sorted=false;
		swap(a[pos],a[size-1]);  //�����ķ����������һ��  
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
     a[i]=rand() % 1000 ;    //����������� 
     
    cout<<"����֮ǰ���飺"; 
   	for(int i=0;i<n;i++)
	cout<<a[i]<<"\t";
	cout<<endl; 
	 
	start=clock();         //��ʼ��ʱ 
    selectionsort(a,n);
	end=clock();         //������ʱ  
	
	dif=end-start;
	
	cout<<"����֮�����飺"; 
	for(int i=0;i<n;i++)
	cout<<a[i]<<"\t";
	
	cout<<endl<<dif<<endl;
	return 0;
}
