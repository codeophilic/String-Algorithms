#include <bits/stdc++.h>
using namespace std;

bool isMatching(string s, string p) {
    int n = s.length();
    int m = p.length();

    for(int i = 0;i<=(n-m);i++) {
        bool ans = true;
        for(int j = 0;j<m;j++) {
            if(s[i+j] != p[j]) {
                ans = false; break;
            }
        }
        if(ans) return true;
    }
    return false;
}

int main() {

    string s, p;
    cin >> s;
    cin >> p;

    cout << isMatching(s, p) << endl;
    return 0;
}