#ifndef  __STACK_H_
#define  __STACK_H_
#include "doublelist.h"
typedef std::string S_Type;

class Stack
{
public:
	Stack();
	~Stack();
	void push(S_Type data);		//入栈
	S_Type pop();				//出栈
	S_Type get_top();			//获取栈顶元素信息
	bool isEmpty();				//判断栈是否为空
	int stack_size();			//获取栈的大小
	void put_stack();			//输出栈中元素信息

private:
	Doublelist list;
};




#endif