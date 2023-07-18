#include <iostream>
#include <map>
#include <string>
using namespace std;


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	map<string, int>Pokemon1; //포켓몬이름->번호
	map<int, string>Pokemon2; //번호->포켓몬이름
	string str; //빈 문자열
	int n,m; //n=포켓몬 개수 , m=맞춰야 하는 문제의 개수
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> str; //문자열 입력
		Pokemon1.insert({ str, i }); //삽입
		Pokemon2.insert({ i, str }); //삽입
	}
	for (int i = 0; i < m; i++)
	{
		cin >> str; //문자열 입력
		if (str[0] >= 'A' && str[0] <= 'Z')
			cout << Pokemon1[str] << '\n'; //key값 str에 대한 value 값 출력
		else
			cout << Pokemon2[stoi(str)] << '\n'; //key값 str(정수변환)에 대한 value 값 출력  
	}
}
