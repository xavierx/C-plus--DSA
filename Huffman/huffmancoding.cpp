#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <fstream>
#include <sstream> 
#include <algorithm> 
using namespace std;
struct Node   //�������ڵ��� ����:�洢���ַ� Ƶ�� ����  
{
	char content;
	int freq;
	string code;
	Node *left;
	Node *right;
	Node(){left=right=NULL;}; 
};

bool compare(Node* a,Node* b)
{
		return a->freq>b->freq;	//���ս������� �Զ���sort�����򷽷� 
}


class HolfTree
{
		private:		
		Node *root;
		void OutPutToStream(Node* p);
		void OutToFileStream(Node * node,string &str,int depth);
		string  NumToStr(int num);
		public:
		HolfTree(){root=new Node();};
		void BulidTree(string filename);
		void OutPut();
		void OutToFile(string str3);
		void OutToString(string filename);
};

string  HolfTree::NumToStr(int num)  //Ϊ�˷����������intת��Ϊstring  
{
	string x;
	stringstream ss;
	ss<<num;
	ss>>x	;
	return x;
};

void HolfTree::BulidTree(string filename)
{
		//��ȡ�ļ��������ļ������������� 
		ifstream in(filename);
		string str;//���ڱ�����ļ��������ַ��� 
		char p;
		while(in.read(&p,1))  //ÿ�ζ�ȡһ���ַ� ����p 
		{
			str+=p;
		}
		//ͳ�Ƹ�����ĸ���ֵ�Ƶ�� 
		string mychar;      //û���ظ����ַ��� 
		vector<int> count;   //ÿ���ַ���Ƶ�� 
		vector<string> allstring;
		for(int i=0;i<str.size();i++)
		{
			
			int pos=-1;   //vector�е�λ�� 
			for(int k=0;k<=mychar.size();k++)
			{	
				if(mychar[k]==str[i]) 
					{
					pos=k;
					break;
					}
			}			
			//���ﲻ����if(pos)����Ϊpos�п�����0 
			if(pos!=-1)
				{
					count[pos]++;   //�Ѿ��д洢�ˣ�Ƶ����1 
				}
			else              //��û�д洢���������������һ��λ�� 
			{
				mychar+=str[i];
				count.push_back(1);					
			}
		}
		//����ĸ��countת��Ϊ�ṹ��Node
		vector<Node *> nodestack;
		for(int i=0;i<mychar.size();i++)
		{
			Node *p=new Node();
			p->content=mychar[i];
			p->freq=count[i];
			nodestack.push_back(p);
		}
		//�����е�node��������nodestack�����ˣ���������������
		while(nodestack.size()!=1)
		{
				//���� - ����  
		  	sort(nodestack.begin(),nodestack.end(),compare);
				
				Node *p=new Node();
				//����������ĩ��Ϊ�Һ��ӣ���ĿҪ�� 
				 	
				p->right=nodestack.back();
				nodestack.pop_back();
				p->left=nodestack.back();
				nodestack.pop_back();
				
				p->content='0';
				p->freq=p->left->freq+p->right->freq; 
				nodestack.push_back(p); //�ٷ���vector��  
		} 
		root=nodestack.back();
		nodestack.pop_back();
};

void  HolfTree::OutPut()
{
	OutPutToStream(root);
};

void HolfTree::OutToFileStream(Node * node,string &str,int depth)
{
	if(node->code.size()==depth)   //ÿһ�����  
	{
	for(int i=0;i<20/(depth+1);i++)
	{
		str+=" ";
	} 	
	 if(node->content=='0')
				{				
				str+=NumToStr(node->freq);
				}
			else
				{		 
				str+=node->content;
				}
	} 
	if(node->left==NULL&&node->right==NULL)
	return;
	OutToFileStream(node->left,str,depth);
	OutToFileStream(node->right,str,depth);
};          

void HolfTree::OutToFile(string str3)
{
		string x,y;
		int i=0;
		do
		{
		y.clear();
		OutToFileStream(root,y,i);
		x+=y;
		x+='\n';
		i++;
		}while(y.size()!=0);
		ofstream out(str3);
		out.write(x.c_str(),x.size());
		out.close();
};

void HolfTree::OutPutToStream(Node* p)  //����  
{
		if(p->content!='0')
		cout<<"char:"<<p->content<<"   frequnce:"<<p->freq<<"   code:"<<p->code<<endl;
		if(p->left==NULL&&p->right==NULL)
		return;
		p->left->code=p->code+'0';
		p->right->code=p->code+'1';
		OutPutToStream(p->left);
		OutPutToStream(p->right);
}


void HolfTree::OutToString(string filename) //��ѹ��  
{
	
		ifstream in(filename);
		string str;//���ڱ�����ļ��������ַ��� 
		char p1;
		while(in.read(&p1,1))
		{
			str+=p1;
		}
		
		Node *p=root;
		for(int i=0;i<str.size();i++)
		{
			if(str[i]=='0')
			{
				p=p->left;
			}
			else
			{
				p=p->right;
			}
			if(p->content!='0') //˵�����ַ�  
			{
				cout<<p->content;
				p=root;
			}
		}
};
int main()
{
	string str1="char.txt";
	cout<<"������������룺"<<endl;
	HolfTree ht;
	ht.BulidTree(str1);
	ht.OutPut();
	string str3="outputfile1.txt";
	ht.OutToFile(str3);
	cout<<"������������룺"<<endl;
	string str2="code.txt";
	ht.OutToString(str2);
} 


