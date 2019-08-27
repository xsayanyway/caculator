#include "stack.h"

Stack::Stack()
{}

Stack::~Stack()
{}

//入栈即往链表中添加数据
void Stack::push(S_Type data)
{
	list.head_insert(data);
}

//出栈即从链表中删除数据
S_Type Stack::pop()
{
	return list.delete_head();
}

//获取栈顶元素信息
S_Type Stack::get_top()
{
	return list.get_head();
}

//判断栈是否为空
bool Stack::isEmpty()
{
	return list.isEmpty();
}

//获取栈的大小
int Stack::stack_size()
{
	return list.list_size();
}

//输出栈中数据信息
void Stack::put_stack()
{
	list.put_list();
}