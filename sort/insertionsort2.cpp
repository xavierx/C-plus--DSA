#include<iostream>
#include <cstdlib>
#include <ctime>
#include"swap.h"
using namespace std;
//�������� �ȶ��� ��� n � n^2 
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
    insertionsort(a,n);
	end=clock();         //������ʱ  
	
	dif=end-start;
	
	cout<<"����֮�����飺"; 
	for(int i=0;i<n;i++)
	cout<<a[i]<<"\t";
	
	cout<<endl<<dif/CLOCKS_PER_SEC<<endl;
	return 0;
}
