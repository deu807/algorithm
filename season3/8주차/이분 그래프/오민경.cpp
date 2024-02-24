#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define RED 2
#define BLUE 3

int K, V, E, u, v;
int visited[20001];    
vector<int> vec[20001];

void DFS(int start) {
	if (visited[start] == 0) visited[start] = RED;
	for (int i = 0; i < vec[start].size(); i++) {
		int index = vec[start][i];
		if (visited[index] == 0) {
			if (visited[start] == RED) visited[index] = BLUE;
			else if (visited[start] == BLUE) visited[index] = RED;

			DFS(index);
		}
	}
}

int check() {
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			int index = vec[i][j];
			if (visited[i] == visited[index]) return false;
		}
	}
	return true;
}

int main() {
	cin >> K;
	while (K--) {
		cin >> V >> E;
		for (int i = 0; i < E; i++) {
			cin >> u >> v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		for (int i = 1; i <= V; i++) {
			if (visited[i] == 0) DFS(i);
		}
		if (check() == 0) cout << "NO\n";
		else cout << "YES\n";

		for (int i = 0; i <= V; i++) {
			visited[i] = 0;
			vec[i].clear();
		}
	}

	return 0;
}