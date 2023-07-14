#include <iostream>
#include <stack>
using namespace std;

//stack<int>s;
bool visited[101]; // 방문 여부
int graph[101][101]; //인접 행렬 방식 이용 위한 이차원 배열 선언
int cnt; // 웜 바이러스에 걸리게 되는 컴퓨터의 수
int cpt1, cpt2; // 컴퓨터의 수 (노드) , 컴퓨터 쌍의 수 (간선) 
void dfs(int x)
{
	//1)재귀함수 이용
	visited[x] = true; //방문여부 표시 
	for(int i=1; i<=cpt1; i++)
	{
		if (!visited[i] && graph[x][i] == 1) //방문하지 않고, 인접할 경우  
		{
			cnt++;
			dfs(i);  
		}
	}

	//2)스택 이용
	//s.push(x);
	
	//visited[x] = true;
	//while (!s.empty())
	//{
	//
	//}
}
int main()
{
	cin >> cpt1 >> cpt2; //노드와 간선 입력
	for (int i = 0; i < cpt2; i++)
	{
		int x, y;
		cin >> x >> y;  //서로 연결되어있는 노드 입력
		graph[x][y] = graph[y][x]= 1; // 인접 행렬 방식(노드들 간 직접 연결이 되어있으면 1) / 연결 방향 존재 x  
	}
	dfs(1); //1에서 부터 시작
	cout << cnt << endl;
	return 0;
}