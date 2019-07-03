#include <bits/stdc++.h>
using namespace std;

int *getLps(string pattern) {

    int len = pattern.size();
    int *lps = new int[len];

    lps[0] = 0;
    int i = 1; int j = 0;

    while(i < len) {

        if(pattern[i] == pattern[j]) {
            lps[i] = j+1;
            j++; i++;
        } else {
            if(j!= 0) {
                j = lps[j-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool kmpSearch(string text, string pattern) {

    int lenText = text.size();
    int lenPat = pattern.size();
    int i = 0;
    int j = 0;

    int *lps = getLps(pattern);
    
    while(i<lenText && j<lenPat) {
        if(text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if(j != 0) {
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }

    if(j == lenPat) {
        return true;
    }
    return false;
}

int main() {

    string str, substring;
    cin >> str >> substring ;
    cout << kmpSearch(str, substring) << endl;
    return 0;
}