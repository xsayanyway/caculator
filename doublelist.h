#ifndef __DOUBLELIST_H_
#define __DOUBLELIST_H_

#include <string>
typedef std::string Type;
class Node
{
public:
	Node(Type value=0); //这个构造函数不带参数也能调用，所以也叫默认构造函数
	~Node();
	friend class Doublelist; //结点类声明了一个朋友是链表类，链表就可以直接访问结点隐藏信息
private:
	Type _data; 	//结点的数据域
	Node* _next;	//结点的指针域
	Node* _prev;
};

class Doublelist
{
public:
	//构造函数
	Doublelist();
	~Doublelist();
	void head_insert(Type value);
	void tail_insert(Type value);
	Type delete_tail();
	Type delete_head();
	Type get_head();
	Type get_tail();
	int list_size();
	bool isEmpty();
	void put_list();

private:
	Node* _phead;//头指针
	Node* _ptail;//尾指针
	int _size;
};


#endif
