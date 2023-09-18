#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int cnt = 0;
    vector<int> fi;
    int P; //테스트 케이스
    cin >> P;
    while (P--)
    {
        int N, M;
        cin >> N >> M;
        fi.clear(); 
        fi.push_back(0);
        fi.push_back(1); //1일떄
        fi.push_back(1); //2일떄

        cnt = 2; //2개 먼저 넣어주고 시작했기때문에 초기값 2
        while (1)
        {
            fi.push_back((fi[cnt] + fi[cnt - 1]) % M);
            cnt++;

            if (fi[cnt] == 0 && fi[cnt - 1] == 1) break;
        }

        cout << N << ' ' << cnt << '\n';
    }

    return 0;
}
