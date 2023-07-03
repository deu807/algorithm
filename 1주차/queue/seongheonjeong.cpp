#include <iostream>
using namespace std;

class Queue
{
	int a[10000];
	int position=0; //인덱스, 현재 위치 front , near
public:
	void push(int x);
	int pop();
	int size();
	int empty();
	int front();
	int back();
	void print()
	{
		for (int i = 0; i < position; i++)
		{
			cout << a[i]<<' ';
		}
	}
};
void Queue::push(int x)
{
	a[position] = x;
	position++;
}
int Queue::pop()
{
	int temp = a[0];
	for (int i = 0; i < position-1; i++)
	{
		a[i] = a[i + 1];
	}
	position--;

	if (position == 0)
		return -1;
	else
		return temp;
}
int Queue::size()
{
	return position;
}
int Queue::empty()
{
	if (position == 0)
		return 1;
	else return 0;
}
int Queue::front()
{
	if (position == 0)
		return -1;
	else 
		return a[0];
}
int Queue::back()
{
	
	if (position == 0)
		return -1;
	else
		return a[position - 1];
}
int main() {
	int n;
	cin >> n;

	Queue Q; 

	while (n--) {
		string str;
		
		cin >> str;

		if (str == "push") {
			int x;
			cin >> x;
			Q.push(x);
		}
		else if (str == "pop") {
			cout << Q.pop() << endl;
		}
		else if (str == "size") {
			cout << Q.size() << endl;
		}
		else if (str == "empty") {
			cout << Q.empty() << endl;
		}
		else if (str == "front") {
			cout << Q.front() << endl;
		}
		else if (str == "back") {
			cout << Q.back() << endl;
		}
		else if (str == "print") {
			Q.print();
			cout << endl;
		}
	}
	return 0;
}
