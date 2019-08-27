#ifndef  __QUEUE_H_
#define  __QUEUE_H_
#include "doublelist.h"
typedef std::string Q_Type;

class Queue
{
public:
	Queue();
	~Queue();
	void enqueue(Q_Type data);		//入队
	Q_Type dequeue();				//出队
	Q_Type get_queueHead();			//获取队头
	bool isEmpty();					//判断队列是否为空
	int queue_size();				//获取队列长度
	void put_queue();				//输出队列

private:
	Doublelist list;
};


#endif