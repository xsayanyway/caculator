#include "doublelist.h"
#include <iostream>
using namespace std;


Node::Node(Type value)
{
	_data = value;
	_next = NULL;
	_prev = NULL;
}

Node::~Node()
{}

Doublelist::Doublelist()
{
	_phead = NULL;
	_ptail = NULL;
	_size = 0;
}

Doublelist::~Doublelist()
{
	Node *p ;
	while (!this->isEmpty())
	{
		p = _phead->_next;
		delete _phead;
		_phead = p;
	}
}

void Doublelist::tail_insert(Type value)
{
	//用拿到的值，创建一个新结点
	Node *pnode = new Node(value);
	
	//把新结点加入到链表中
	//如果是空的链表
	//如果不空
	if (this->isEmpty())
	{
		_phead = pnode;
		_ptail = pnode;
	}
	else
	{
		_ptail->_next = pnode;
		pnode->_prev = _ptail;
		_ptail = pnode;
	}
	_size++;
}

void Doublelist::head_insert(Type value)
{
	//用拿到的值，创建一个新结点
	Node *pnode = new Node(value);
	
	//把新结点加入到链表中
	//如果是空的链表
	//如果不空
	if (this->isEmpty())
	{
		_phead = pnode;
		_ptail = pnode;
	}
	else
	{
		pnode->_next = _phead;
		_phead->_prev = pnode;
		_phead = pnode;
	}
	_size++;
}

int Doublelist::list_size()
{
	return _size;
}
//是不是空
bool Doublelist::isEmpty()
{
	return _phead == NULL;
}
//打印测试
void Doublelist::put_list()
{
	Node *p = _phead;
	for (int i = 0; i < this->list_size(); ++i)
	{
		cout << p->_data << "  " ;
		p = p->_next;
	}
	cout << endl;
}

Type Doublelist::delete_tail()
{
	//...
	Type value = _ptail->_data;
	if (_size == 1)
	{
		delete _phead;
		_phead = NULL;
		_ptail = NULL;
	}
	else
	{
		Node* p = _ptail;
		_ptail = _ptail->_prev;
		_ptail->_next = NULL;
		delete p;
	}
	_size--;
	return value;
}

Type Doublelist::delete_head()
{
	//..
	Type value = _phead->_data;
	if (_size == 1)
	{
		delete _phead;
		_phead = NULL;
		_ptail = NULL;
	}
	else
	{
		Node *pt = _phead->_next;
		pt->_prev = NULL;
		delete _phead;
		_phead = pt;
	}
	_size--;
	return value;
}

Type Doublelist::get_tail()
{
	return _ptail->_data;
}

Type Doublelist::get_head()
{
	return _phead->_data;
}