#ifndef  __CALCULATOR_H_
#define  __CALCULATOR_H_
#include "stack.h"
#include "queue.h"
#include "doublelist.h"
#include <string>
#include <map>
using std::string;

class Calculator
{
public:
	Calculator();
	~Calculator();
	double calculate(string expr);//计算表达式的值
	
private:
	double _result;  	//保存计算结果
	Queue _expr;		//保存中缀表达式队列
	Stack _digit;		//数字栈
	Stack _symbol;		//符号栈
	
private:
	bool isValid(string str);								//判断表达式是否合法
	bool isDigit(char c);									//判断是否是数字
	bool isSymbol(char c);									//判断是否是运算符
	bool isSymbol(string c);								//重载函数
	int priority(string op);								//获取表达式的优先级
	void analysis_expr(string str);							//解析表达式并入队
	void operate_expr();									//表达式的运算
	string calculate(string s1, string op, string s2);		//计算2个数的加减乘除
	void push_symbol(string str);							//符号入栈
	void deleteMark(string &s,const string &mark);			//删除表达式中的空格
};


#endif