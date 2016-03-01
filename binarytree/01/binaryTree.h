#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
#include "Stack.h"
 
#ifndef BINARYTREE_H 
#define BINARYTREE_H 
class Tnode
{
public:
         char value;
         Tnode *left,*right;
         Tnode(){}
         Tnode(const char value,Tnode *left=NULL,Tnode *right=NULL):value(value), left(left), right(right)
         {}
         Tnode* buildTree(string exp);//��׺���ʽ���ɶ�����
         int depth(Tnode *root);//��������
         void print(Tnode *node_ptr, int depth);//ת���ӡ������(��ʱ��ת90�ȴ�ӡ)
        // void inorderOutput(Tnode *t);
};
 //��׺���ʽ���ɶ�����
Tnode* Tnode::buildTree(string exp)
{
         Tnode *ptr;         
         Stack<Tnode*>nodeStack;
         char c;
         int i=0;
         c=exp[i++];
         while(c!='\0')
         {
                   if(c!='+' && c!='-' && c!='*' && c!='/')
                   {
                            ptr=new Tnode(c);
                            nodeStack.push(ptr);
                            c=exp[i++];
                   }
                   else
                   {
                            ptr=new Tnode(c);
                            if(!nodeStack.empty())
                            {
                                     ptr->right=nodeStack.top();
                                     nodeStack.pop();
                            }
                            if(!nodeStack.empty())
                            {
                                     ptr->left=nodeStack.top();
                                     nodeStack.pop();
                            }
                            nodeStack.push(ptr);
                            c=exp[i++];
                   }
         }
         return ptr;
}
 
//��������  
int Tnode::depth(Tnode *root)
{
         int i,j;
         if(root==NULL)
                   return 0;
         i=depth(root->left);
         j=depth(root->right);
         return i>j?i+1:j+1; 
}
 
 
 

void Tnode::print(Tnode *node_ptr, int depth)//��ʱ��90�ȴ�ӡ������(ֱ�����)
{ 
         if (node_ptr!= NULL)
    {
        print(node_ptr->right, depth+1);
        cout<<setw(3*depth)<<" ";
        cout<<node_ptr->value<<endl;
        print(node_ptr->left,depth+1);
    }
}
 

 
 
/*
void Tnode::inorderOutput(Tnode *t)  //�������
{
         if(t!=NULL)
         {
                   inorderOutput(t->left);
                   cout<<t->value;
                   inorderOutput(t->right);
         }
}
*/
#endif
