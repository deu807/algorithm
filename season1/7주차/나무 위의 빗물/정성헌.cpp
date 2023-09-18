#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, W; //노드의 수 , 1번 노드에 고인 물의 양
int U, V; //간선의 정보
vector <int> v[500001]; //노드
bool visited[500001]; //방문 여부 확인
int leaf; //리프 노드의 개수

void bfs(int n)
{
   queue<int> q;
   q.push(n);
   visited[n] = true;

   while (!q.empty())
   {
       int x = q.front();
       q.pop();
       
       bool isleaf = true; // x를 리프노드라 가정 / 초기값 true로 설정

       for (int i = 0; i < v[x].size(); i++)
       {
           int y = v[x][i];
           
           if (!visited[y]) //방문하지 않았을 경우
           {  
               q.push(y);
               visited[y] = true;
               isleaf = false; 
           }
       }
       if (isleaf)
           leaf++;
   }
}
int main()
{
   cin >> N >> W; //노드의 수, 1번 노드에 고인 물의 양 입력
   for (int i = 0; i < N - 1; i++)
   {
       cin >> U >> V; //간선 정보 입력
       v[U].push_back(V); //서로 연결
       v[V].push_back(U);
   }

   bfs(1);

   cout.precision(10);  //10째 자리 수 까지 출력
   
   cout << W / (double)leaf; // 물의 양 / 리프 노드의 수
}