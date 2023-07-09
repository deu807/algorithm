#include <iostream>

using namespace std;

class Stack
{
	
	int p[10000];
	int topI = -1;
public:
	void push(int x);
	int pop();
	int size();
	int empty();
	int top();
};
void Stack::push(int x)
{
	p[++topI] = x;
}
int Stack::pop()
{
	if (empty())
		return -1;
	else
		return p[topI--];
}
int Stack::size()
{
	return topI + 1;
}
int Stack::empty()
{
	if (topI == -1)
		return 1;
	else return 0;
}
int Stack::top()
{
	if (empty())
		return -1;
	else
		return p[topI];
}
int main()
{
	Stack s;
	int n;
	int num;
	cin >> num;

	string str;
	while (num--)
	{
		cin >> str;
		
		if (str == "push")
		{
			cin >> n;
			s.push(n);
		}
		else if (str == "pop")
		{
			cout << s.pop() << endl;
		}
		else if (str == "size")
		{
			cout << s.size() << endl;
		}
		else if (str == "empty")
		{
			cout << s.empty() << endl;
		}
		else if (str == "top")
		{
			cout << s.top() << endl;
		}
	}
	return 0;
}