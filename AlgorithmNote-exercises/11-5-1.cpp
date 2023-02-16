#include<cassert>
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

string str;
vector<vector<int>> vec;

bool isPalin(int i, int j) {
    assert(i <= j);
    if (vec[i][j] != -1) {
        return vec[i][j];
    }
    if (isPalin(i + 1, j - 1) && str[i] == str[j]) {
        vec[i][j] = 1;
        return true;
    } else {
        vec[i][j] = 0;
        return false;
    }
}

int main() {
    cin >> str;
    vec = vector<vector<int>>(str.length(), vector<int>(str.length(), -1));
    for (int i = 0; i < str.length(); i++) {
        vec[i][i] = 1;
        if (i != str.length() - 1) {
            if (str[i] == str[i + 1]) {
                vec[i][i + 1] = 1;
            } else {
                vec[i][i + 1] = 0;
            }
        }
    }

    for (int i = str.length() - 1; i >= 0; i--) {
        for (int j = 0; i + j < str.length(); j++) {
            if (isPalin(j, i + j)) {
                cout << i + 1;
                goto label;
            }
        }
    }


label:
    return 0;
}