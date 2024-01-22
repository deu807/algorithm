#include <iostream>
#include <vector>
using namespace std;

int s, p;
int cnt = 0;
string dna;
vector<int>ACGT(100, 0);
vector<int>update(100, 0);		//ACGT 업데이트
int main()
{
	cin >> s >> p;
	cin >> dna;

	// 문자를 인덱스로 사용
	cin >> ACGT['A'];
	cin >> ACGT['C'];
	cin >> ACGT['G'];
	cin >> ACGT['T'];

	// 슬라이딩 윈도우 앞 뒤 지정
	int f = 0;
	int b = f + p - 1;

	// dna 문자 하나하나 검사하여 해당 문자의 개수 증가
	for (int i = 0; i < p; i++)
	{
		update[dna[i]]++;
	}

	while (b < dna.size())
	{
		if (ACGT['A'] <= update['A'] && ACGT['C'] <= update['C'] && ACGT['G'] <= update['G'] && ACGT['T'] <= update['T'])	cnt++;
		// 슬라이딩 윈도우 이동. 맨 앞을 빼고 맨 뒤를 추가하는 형식
		update[dna[f++]]--;
		update[dna[++b]]++;
	}

	cout << cnt;

	return 0;
}