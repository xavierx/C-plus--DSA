#include<iostream>
#include<string>
using namespace std;
#include "Stack.h"
#include "postfix.h"
#include "binaryTree.h"
 
int main()
{
        // string infix="a+b+c*(d+e)";  //输入的中缀表达式  
         string infix;
         cout<<"请输入中缀表达式"<<endl;
         getline(cin,infix);
         string s=postfix(infix); //s为输出化为的后缀表达式  
         cout<<"后缀表达式为："<<s<<endl;
         Tnode tree(' ');
         Tnode *root;
         int high;
         root=tree.buildTree(s);
         high=tree.depth(root);
         tree.print(root,high);
         
       
}
