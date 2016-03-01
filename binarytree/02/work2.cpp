 
#include<queue> 
#include <iostream>
using namespace std;
 
 
class Tnode                //二叉树 数据结构 
{
public:
         int data;            
         Tnode *left,*right;
         Tnode(){}
         Tnode(const char data,Tnode *left=NULL,Tnode *right=NULL):data(data), left(left), right(right)
         {}
        
};
 
 
Tnode *arrayTotree(int a[] , int start,int end )  //按照中序顺序的数组输入 生成二叉树 

    {
           if(start>end)
           {
               return NULL;
           }

           int m = start+(end-start)/2;    //数组中间的数就是根节点 （中序遍历） 

           Tnode *root = new Tnode();

          root->data = a[m];              

          root->left=arrayTotree(a,start,m-1);  //递归构建左右子树  

          root->right=arrayTotree(a,m+1,end);

          return root;              //返回根节点  

     }
     
void preOrder(Tnode*T){    //先序遍历 
     
    if(T)
    {
       
        if(T->data!=0)          //0在本题中实际为NULL 因此不输出  
        cout<<T->data<<" ";
         preOrder(T->left);
        preOrder(T->right);
    }
}


/*按层遍历：利用队列的特征，先输出根节点，再将它的孩子们放入队列中，再进行递归。
因此可以实现父节点肯定先于子节点输出，并且左孩子肯定先于右孩子输出，这样就实现了按层输出。*/
void levelOrder(Tnode*t){      //按层遍历 运用队列   
	queue<Tnode*> Q ;
	while(t){
		if(t->data!=0) cout<<t->data<<" ";
		if(t->left) Q.push(t->left);
		if(t->right) Q.push(t->right);
		
		if(Q.empty())	return;
		t=Q.front();           //返回队列头元素赋给t 
		Q.pop();               //删除队列头元素  
		
	}
}


int getWidth(Tnode *pRoot)  //求宽度  
{  
    if (pRoot == NULL)  
    {  
        return 0;  
    }  
  
    int nLastLevelWidth = 0;//记录上一层的宽度  
    int nTempLastLevelWidth = 0;  
    int nCurLevelWidth = 0;//记录当前层的宽度  
    int nWidth = 1;//二叉树的宽度  
    queue<Tnode *> myQueue;  
    myQueue.push(pRoot);//将根节点入队列  
    nLastLevelWidth = 1;      
    Tnode *pCur = NULL;  
  
    while (!myQueue.empty())//队列不空  
    {  
        nTempLastLevelWidth = nLastLevelWidth;  
        while (nTempLastLevelWidth != 0)  
        {  
            pCur = myQueue.front();//取出队列头元素  
            myQueue.pop();//将队列头元素出队 
  
            if (pCur->left != NULL &&pCur->left->data!=0)  
            {  
                myQueue.push(pCur->left);  
            }  
  
            if (pCur->right != NULL&&pCur->right->data!=0)  
            {  
                myQueue.push(pCur->right );  
            }  
  
            nTempLastLevelWidth--;  //把上一层的元素都清出队列，并且加入下一层元素入队 
        }  
  
        nCurLevelWidth = myQueue.size();  //队列中只剩同一层元素  
        nWidth = (nCurLevelWidth > nWidth ? nCurLevelWidth : nWidth);  
        nLastLevelWidth = nCurLevelWidth;  
    }  
  
    return nWidth;  
}  


void exchange(Tnode * node)      //利用递归 交换左右子树  
{
   if(node == NULL) return;
   Tnode * temp = node->left;
   node->left = node->right;
   node->right = temp;

   exchange(node->left);
   exchange(node->right);
}



int main(){
	 int inOrderarray[]={9,10,14,5,6,26,0,7,0,2,28,8,3,19,0,15,0,0,0,26,18,8,0,18,0,0,0,1,14,6,27}; //将树补成满二叉树  
	 Tnode*tree;
	 tree=arrayTotree(inOrderarray,0,30);
	 cout<<"先序输出为："; 
	 preOrder(tree);
	 cout<<endl;
	 cout<<"按层输出为：";
	 levelOrder(tree);
	 int wide= getWidth(tree);
	 cout<<endl<<"宽度为"  <<wide<<endl;
	 exchange(tree);
	 cout<<"交换后按层输出为：";
	 levelOrder(tree);
}
