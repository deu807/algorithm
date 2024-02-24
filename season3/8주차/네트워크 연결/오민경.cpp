#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int parent[1001];
int answer;
vector<pair<int, pair<int, int>>> graph;

int find(int x) {	//find : 연결 중 루트노드를 찾기 위해 사용
	if (parent[x] == x) return x;
	else return parent[x] = find(parent[x]);
}
void Union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) parent[y] = x;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
    
	int a, b, c;
	for (int i = 0; i < M; i++) {
		a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph.push_back({ c, {a,b} });
	}

	sort(graph.begin(), graph.end());

	for (int i = 0; i < graph.size(); i++) {
		int a = find(graph[i].second.first);
		int b = find(graph[i].second.second);
		if (a != b) {
			Union(graph[i].second.first, graph[i].second.second);
			answer += graph[i].first;
		}
	}
	cout << answer << endl;
	return 0;
}