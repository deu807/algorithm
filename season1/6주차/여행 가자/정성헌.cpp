#include <iostream>

using namespace std;

int parent[201]; //부모 노드 저장
int arr[201][201]; //도시들 간의 연결정보 저장
int a[1001]; //여행 계획 저장

int find(int x) //부모 노드 반환
{
	if (x == parent[x])
		return x;
	else  //경로 압축
	{
		parent[x] = find(parent[x]); 
		return parent[x];
	}
}
void Union(int x, int y) //집합 합쳐줌
{
	x = find(x);  // x의 부모 노드 반환.
	y = find(y);  // y의 부모 노드 반환.
	
	if (x == y) //부모 노드가 같을 시 
		return;
	if (x < y)  //부모 노드가 다를 시 다시 설정
		parent[y] = x; 
	else
		parent[x] = y;
}
int main()
{
	int n, m; //n=도시의 수,m=여행 계획에 속한 도시의 수
	cin >> n >> m;

	for (int i = 1; i <= n; i++) 
		parent[i] = i; //부모 노드가 자신을 가르키도록 초기화
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++) 
		{
			cin >> arr[i][j]; // 연결되어 있는 도시 입력

			if (arr[i][j] == 1)
				Union(i, j);
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		cin >> a[i]; //여행 계획 
	}
	bool check = true; //초기 값 true
	for (int i = 0; i < m-1; i++) {
		if (find(a[i]) != find(a[i+1])) { //부모 노드가 다를 경우
			check = false;
			break;
		}
	}
	if (check) cout << "YES"<<'\n';
	else cout << "NO"<<'\n';

	return 0;
}
