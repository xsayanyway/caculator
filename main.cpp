#include <iostream>
#include "doublelist.h"
#include "queue.h"
#include "stack.h"
#include "calculator.h"
using namespace std;

int main(int argc, char const *argv[])
{
	cout << "请输入一个表达式：";
	string expr;
	getline(cin, expr);

	Calculator calc; //创建对象时，自动调用构造函数，以初始化成员变量
	try
	{
		double res = calc.calculate(expr);
		cout << "res = " << res << endl;
	}
	catch(const char* err)
	{
		cout << err << endl;
	}
	
	return 0;
}