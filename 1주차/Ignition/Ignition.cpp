#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for (auto t : quiz) {
        istringstream iss(t);

        int x, y, z;
        char op, res;

        iss >> x >> op >> y >> res >> z;

        if((op == '+' && z == x+y) || (op == '-' && z == x-y)) answer.push_back("O");
        else answer.push_back("X");
    }
    return answer;
}

int main() {

    vector<string> v = { "-10000 - -10000 = 20000", "5 + 66 = 71", "5 - 15 = 63", "3 - 1 = 2" };

    vector<string> res = solution(v);
    for (auto i : res) {
        cout << i;
    }
}