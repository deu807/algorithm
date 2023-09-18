#include <queue> queue<int> q;
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int N;
  queue<int> queue;

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    string input = "";
    int num = 0;
    cin >> input;

    if (input == "push")
    {
      cin >> num;
      queue.push(num);
    }
    else if (input == "pop")
    {
      if (queue.empty() == 1)
      {
        cout << -1 << endl;
        continue;
      }
      cout << queue.front() << endl;
      queue.pop();
    }

    else if (input == "size")
    {
      cout << queue.size() << endl;
    }
    else if (input == "empty")
    {
      cout << queue.empty() << endl;
    }

    else if (input == "front")
    {
      if (queue.empty())
      {
        cout << -1 << endl;
        continue;
      }
      cout << queue.front() << endl;
    }

    else if (input == "back")
    {
      if (queue.empty())
      {
        cout << -1 << endl;
        continue;
      }
      cout << queue.back() << endl;
    }
  }
}