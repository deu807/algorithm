#include <iostream>
#define MAX_SIZE 1000000

using namespace std;

class Queue
{
    int* a = new int[MAX_SIZE]; //동적 할당 
    int frontI = 0; //삭제 인덱스
    int rearI = 0; //삽입 인덱스 
public:
    void push(int x); 
    int pop();        
    int size();
    int empty();
    int front();
    int back();
};

void Queue::push(int x)
{
    if (rearI < MAX_SIZE) {
        a[rearI++] = x;
    }
}

int Queue::pop()
{
    return a[frontI++];
}

int Queue::size()
{
    return rearI - frontI;
}

int Queue::empty()
{
    if (rearI == frontI)
        return 1;
    else
        return 0;
}

int Queue::front()
{
    if (rearI == frontI)
        return -1;
    else
        return a[frontI];
}

int Queue::back()
{
    if (rearI == frontI)
        return -1;
    else
        return a[rearI];
}

int main()
{
    Queue Q;
    int N;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        Q.push(i);
    }


    while (Q.size() > 1) {
        Q.pop();
        Q.push(Q.pop());
       
    }

    cout << Q.front();

    return 0;
}