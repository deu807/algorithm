#include <iostream>
using namespace std;

typedef long long ll;

ll x1, y1, x2, y2, x3, y3, x4, y4;

int inclin(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
    ll d1, d2;
    
    d1 = x1*y2 + x2*y3 + x3*y1;
    d2 = y1*x2 + y2*x3 + y3*x1;
    //cout << d1 << ' ' << d2 << '\n';
    ll disc = d1 - d2;
    
    if(disc > 0)
        return 1;
    else if(disc < 0)
        return -1;
    else
        return 0;
}

void input(){
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
}

void solve(){
    int ccw1, ccw2;
    
    // A B C * A B D
    ccw1 = inclin(x1,y1, x2,y2, x3,y3) * inclin(x1,y1, x2,y2, x4, y4);
    // C D A * C D B
    ccw2 = inclin(x3,y3, x4,y4, x1,y1) * inclin(x3,y3, x4,y4, x2,y2);
    
    //cout << ccw1 << ccw2 << '\n';
    if(ccw1 == -1 && ccw2 == -1)
        cout << 1;
    else
        cout << 0;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    input();
    solve();
}