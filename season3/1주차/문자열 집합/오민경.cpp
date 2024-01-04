#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, count;
    cin >> N >> M;
    map<string, string> z;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        z.insert({ s, "a" });
    }
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        if (z.find(s) != z.end()) {
            count++;
        }
    }
    cout << count;
    return 0;
}

//런타임 에러 (NZEC) -> 프로그램 main함수에서 0이 아닌 수를 반환해서 발생
//왜 운영체제에 값을 반환할까? 이 값을 상태 코드(status code)라고 하며, 
//프로그램이 성공적으로 실행되었는지를 알려준다. 규칙에 따라 반환 값 0은 성공을 의미하고 양수 값은 실패를 의미한다.