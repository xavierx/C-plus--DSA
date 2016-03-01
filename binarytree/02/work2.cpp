 
#include<queue> 
#include <iostream>
using namespace std;
 
 
class Tnode                //������ ���ݽṹ 
{
public:
         int data;            
         Tnode *left,*right;
         Tnode(){}
         Tnode(const char data,Tnode *left=NULL,Tnode *right=NULL):data(data), left(left), right(right)
         {}
        
};
 
 
Tnode *arrayTotree(int a[] , int start,int end )  //��������˳����������� ���ɶ����� 

    {
           if(start>end)
           {
               return NULL;
           }

           int m = start+(end-start)/2;    //�����м�������Ǹ��ڵ� ����������� 

           Tnode *root = new Tnode();

          root->data = a[m];              

          root->left=arrayTotree(a,start,m-1);  //�ݹ鹹����������  

          root->right=arrayTotree(a,m+1,end);

          return root;              //���ظ��ڵ�  

     }
     
void preOrder(Tnode*T){    //������� 
     
    if(T)
    {
       
        if(T->data!=0)          //0�ڱ�����ʵ��ΪNULL ��˲����  
        cout<<T->data<<" ";
         preOrder(T->left);
        preOrder(T->right);
    }
}


/*������������ö��е���������������ڵ㣬�ٽ����ĺ����Ƿ�������У��ٽ��еݹ顣
��˿���ʵ�ָ��ڵ�϶������ӽڵ�������������ӿ϶������Һ��������������ʵ���˰��������*/
void levelOrder(Tnode*t){      //������� ���ö���   
	queue<Tnode*> Q ;
	while(t){
		if(t->data!=0) cout<<t->data<<" ";
		if(t->left) Q.push(t->left);
		if(t->right) Q.push(t->right);
		
		if(Q.empty())	return;
		t=Q.front();           //���ض���ͷԪ�ظ���t 
		Q.pop();               //ɾ������ͷԪ��  
		
	}
}


int getWidth(Tnode *pRoot)  //����  
{  
    if (pRoot == NULL)  
    {  
        return 0;  
    }  
  
    int nLastLevelWidth = 0;//��¼��һ��Ŀ��  
    int nTempLastLevelWidth = 0;  
    int nCurLevelWidth = 0;//��¼��ǰ��Ŀ��  
    int nWidth = 1;//�������Ŀ��  
    queue<Tnode *> myQueue;  
    myQueue.push(pRoot);//�����ڵ������  
    nLastLevelWidth = 1;      
    Tnode *pCur = NULL;  
  
    while (!myQueue.empty())//���в���  
    {  
        nTempLastLevelWidth = nLastLevelWidth;  
        while (nTempLastLevelWidth != 0)  
        {  
            pCur = myQueue.front();//ȡ������ͷԪ��  
            myQueue.pop();//������ͷԪ�س��� 
  
            if (pCur->left != NULL &&pCur->left->data!=0)  
            {  
                myQueue.push(pCur->left);  
            }  
  
            if (pCur->right != NULL&&pCur->right->data!=0)  
            {  
                myQueue.push(pCur->right );  
            }  
  
            nTempLastLevelWidth--;  //����һ���Ԫ�ض�������У����Ҽ�����һ��Ԫ����� 
        }  
  
        nCurLevelWidth = myQueue.size();  //������ֻʣͬһ��Ԫ��  
        nWidth = (nCurLevelWidth > nWidth ? nCurLevelWidth : nWidth);  
        nLastLevelWidth = nCurLevelWidth;  
    }  
  
    return nWidth;  
}  


void exchange(Tnode * node)      //���õݹ� ������������  
{
   if(node == NULL) return;
   Tnode * temp = node->left;
   node->left = node->right;
   node->right = temp;

   exchange(node->left);
   exchange(node->right);
}



int main(){
	 int inOrderarray[]={9,10,14,5,6,26,0,7,0,2,28,8,3,19,0,15,0,0,0,26,18,8,0,18,0,0,0,1,14,6,27}; //����������������  
	 Tnode*tree;
	 tree=arrayTotree(inOrderarray,0,30);
	 cout<<"�������Ϊ��"; 
	 preOrder(tree);
	 cout<<endl;
	 cout<<"�������Ϊ��";
	 levelOrder(tree);
	 int wide= getWidth(tree);
	 cout<<endl<<"���Ϊ"  <<wide<<endl;
	 exchange(tree);
	 cout<<"�����󰴲����Ϊ��";
	 levelOrder(tree);
}
