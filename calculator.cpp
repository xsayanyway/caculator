#include "calculator.h"
#include <iostream>
using namespace std;
//Calculator类的造构函数
Calculator::Calculator()
{
	_result = 0;//初始化为0
}

//Calculator类的析构函数
Calculator::~Calculator()
{

}

//计算表达式的值
double Calculator::calculate(string expr)
{
	//去除表达式中的空格
	deleteMark(expr," ");
	//判断输入的字符串是否合法
	if(isValid(expr))
	{
		throw "The entered expression is not valid";
	}
	//解析字符串
	analysis_expr(expr);
	//字符串运算
	operate_expr();
	//返回计算结果。
	return _result;
}

//表达式的拆解分析，并入队
void Calculator::analysis_expr(string str)
{
	//遍历整个字符串表达式
	//分离操作数与运算符
	//以运算符为分界点，碰到运算符，就说明一个数字提取完成，保存到队列，把运算符也保存到队列
	string tmp;
	for (int i = 0; i < str.size(); ++i)
	{
		//如果是数字，保存到临时变量中
		if (isDigit(str[i]))
		{
			tmp += str[i];
		}
		//如果是运算符
		else if (isSymbol(str[i]))
		{
			if(str[i] == '(')
			{
				_expr.enqueue({str[i]});// -std=c++11
			}
			else if(str[i-1] == ')')
			{
				_expr.enqueue({str[i]});// -std=c++11
			}
			else
			{
				_expr.enqueue(tmp);
				_expr.enqueue({str[i]});// -std=c++11
				tmp.clear(); // 大多数的能存储其它对象的对象，都应该有一个清空函数 
			}
			
		}
	}
	//遍历表达式完成后，最后一个操作数还保存在tmp变量中
	_expr.enqueue(tmp);
}

//表达式的入栈出栈操作操作
void Calculator::operate_expr()
{
	//遍历中缀表达式队列，是数字直接加入后缀表达式列队，是运算号则入栈
	while (!_expr.isEmpty())
	{
		string str = _expr.dequeue(); //从中缀表达式队列中提取一个字符串
		if (isSymbol(str)) //符号入栈
		{
			//入栈
			push_symbol(str);
		}
		else //如果是数字，直接入栈
		{
			_digit.push(str);
		}
	}

	while(!_symbol.isEmpty())
	{
		string sym = _symbol.pop();
		string s2 = _digit.pop();
		string s1 = _digit.pop();
		string res = calculate(s1, sym, s2);
		_digit.push(res);
	}
	_result = stod(_digit.pop());
}

//符号入栈操作
void Calculator::push_symbol(string str)
{
	while (true)
	{
		if (_symbol.isEmpty()) //栈空时，直接入栈
		{
			_symbol.push(str);
			return;
		}
		else
		{
			if(str == "(")//左括号直接入栈
			{
				_symbol.push(str);
				return;
			}
			else if(str == ")")//右括号则弹出两个数字进行运算，并将结果入栈，直到遇到左括号
			{
				while(1)
				{
					string sym = _symbol.pop();
					if(sym == "(")
					{
						break;
					}
					string s2 = _digit.pop();
					string s1 = _digit.pop();
					string res = calculate(s1, sym, s2);
					_digit.push(res);
				}
				return;
			}
			else if (priority(str) > priority(_symbol.get_top()))  //str优先级比top高，直接入栈
			{
				_symbol.push(str);
				return;
			}
			else 			//str符号优先级比栈顶元素优先级低或者优先级相等
			{				//弹出两个数字和一个符号进行运算，直到栈为空或者
				while(1)	//str符号优先级大于栈顶元素优先级
				{	
					string sym = _symbol.pop();
					string s2 = _digit.pop();
					string s1 = _digit.pop();
					string res = calculate(s1, sym, s2);
					_digit.push(res);
					if (_symbol.isEmpty() || priority(str) > priority(_symbol.get_top()) )
					{
						break;
					}
				}
				_symbol.push(str);
				return;
			}
		}
	}
}

// 具体计算: 计算两个操作数的加减乘除
string Calculator::calculate(string s1, string op, string s2)
{
	double num1 = stod(s1);
	double num2 = stod(s2);
	double result;

	if (op == "+")
	{
		result = num1 + num2;
	}
	else if (op == "-")
	{
		result = num1 - num2;
	}
	else if (op == "*")
	{
		result = num1 * num2;
	}
	else if (op == "/")
	{
		if (num2 == 0)
		{
			throw "除数不能为零！";
		}
		result = num1 / num2;
	}
	else if(op == "%")
	{
		result = (int)num1 % (int)num2;
	}

	string str_result = to_string(result);
	return str_result;
}

//判断运算符的优先级
int Calculator::priority(string op)
{
	if (op == "*" || op == "/" || op == "%")
	{
		return 2;
	}
	else if (op == "+" || op == "-")
	{
		return 1;
	}
	else if(op == "(")
	{
		return 0;
	}
}

//判断输入的字符串表达式是否合法
bool Calculator::isValid(string str)
{
	for (int i = 0; i < str.size(); ++i)
	{
		if(!isDigit(str[i]) || !isSymbol(str[i]))
		{
			return false;
		}//字符串中不能连续出现2个相邻的运算符
		else if((str[i] == '+' || str[i] == '-' || str[i] == '*' ||str[i] == '/' || str[i] == '%') 
			&& (str[i-1] == '+' || str[i-1] == '-' || str[i-1] == '*' ||str[i-1] == '/' || str[i-1] == '%'))
		{
			return false;
		}
	}
	return true;
}

//判断字符c是否是数字
bool Calculator::isDigit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

//判断字符c是否是运算符
bool Calculator::isSymbol(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '(' || c == ')')
	{
		return true;
	}
	else
	{
		return false;
	}
}

//判断字符串c是部署运算符
bool Calculator::isSymbol(string c)
{
	if (c == "+" || c == "-" || c == "*" || c == "/" || c == "%" || c == "(" || c == ")")
	{
		return true;
	}
	else
	{
		return false;
	}
}

//删除string类型字符串中的空格符
void Calculator::deleteMark(string &s,const string &mark)
{
	size_t size = mark.size();
	while(1)
	{
		size_t pos =s.find(mark);
		if(pos == string::npos)
		{
			return;
		}
		s.erase(pos,size);
	}
}
