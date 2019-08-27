#include "queue.h"

Queue::Queue()
{

}

Queue::~Queue()
{

}

//入队即往链表中加入数据
void Queue::enqueue(Q_Type data)
{
	list.tail_insert(data);
}

//出队即删除链表中的节点
Q_Type Queue::dequeue()
{
	return list.delete_head();
}

//获取队头信息
Q_Type Queue::get_queueHead()
{
	return  list.get_head();
}

//判断队列是否为空
bool Queue::isEmpty()
{
	return list.isEmpty();
}

//获取队列的长度
int Queue::queue_size()
{
	return list.list_size();
}

//输出队列信息
void Queue::put_queue()
{
	list.put_list();
}