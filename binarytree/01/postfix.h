#include<iostream>
#include<string>
using namespace std;
#include "Stack.h"

#ifndef POSTFIX_H
#define POSTFIX_H
/*由中缀表达式化为后缀表达式 
中缀表达式转后缀表达式的方法：
1.遇到操作数：直接输出（添加到后缀表达式中）
2.栈为空时，遇到运算符，直接入栈
3.遇到左括号：将其入栈
4.遇到右括号：执行出栈操作，并将出栈的元素输出，直到弹出栈的是左括号，左括号不输出。
5.遇到其他运算符：加减乘除：弹出所有优先级大于或者等于该运算符的栈顶元素，然后将该运算符入栈
6.最终将栈中的元素依次出栈，输出。*/
string postfix(string exp)
{
         char token;     //当前读取的字符 
         string s;
         Stack<char>opStack;
         string postfixExp;  //目标后缀表达式
         for(int i=0;i<exp.length();i++)
         {
                   token=(char)exp[i]; 
                   switch(token) 
                   {
                   case '(':
                            opStack.push(token); //是 ( 则放入栈中 
                            break;
                   case ')':
                            while(opStack.top()!='(') //将与之匹配的（之前的所有元素出栈 
                            {
                                     s=opStack.top();
                                     postfixExp.append(s);
                                     opStack.pop();
                            }
                            opStack.pop();
                            break;
                   case '+'://若栈为空 或 栈顶为（ 或 当前为*/ 且栈顶为 +- （当前运算符优先级更高） 则直接入栈 
                   case '-':
                   case '*':
                   case '/':
                            if(opStack.empty()||opStack.top()=='('||(token=='*'||token=='/')&&(opStack.top()=='+'||opStack.top()=='-'))
                            {
                                     opStack.push(token);
                            }
                            else //若优先级低于栈顶元素  
                            {
                                     s=opStack.top();
                                     postfixExp.append(s);
                                     opStack.pop();
                                     if(opStack.top()=='+'||opStack.top()=='-')
                                     {
                                               s=opStack.top();
                                               postfixExp.append(s);
                                               opStack.pop();
                                     }
                                     opStack.push(token);
                            }
                            break;
                   default: //若为操作数则直接输出  
                                     s=token;
                                     postfixExp.append(s);
                                     break;
                   }
         }
         while(!opStack.empty())   //将栈中剩余的元素依次输出  
         {
                   s=opStack.top();
                   postfixExp.append(s);
                   opStack.pop();
         }
         return postfixExp;
};

#endif
