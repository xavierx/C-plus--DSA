#include<iostream>
#include<string>
using namespace std;
#include "Stack.h"
#include "postfix.h"
#include "binaryTree.h"
 
int main()
{
        // string infix="a+b+c*(d+e)";  //�������׺���ʽ  
         string infix;
         cout<<"��������׺���ʽ"<<endl;
         getline(cin,infix);
         string s=postfix(infix); //sΪ�����Ϊ�ĺ�׺���ʽ  
         cout<<"��׺���ʽΪ��"<<s<<endl;
         Tnode tree(' ');
         Tnode *root;
         int high;
         root=tree.buildTree(s);
         high=tree.depth(root);
         tree.print(root,high);
         
       
}
