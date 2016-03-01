#ifndef SWAP_H
#define SWAP_H
#include<iostream> 

using namespace std;

void swap(int& a, int &b){
	int t;
	t=a;
	a=b;
	b=t;
}

#endif
