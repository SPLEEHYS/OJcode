// https://www.noobdream.com/DreamJudge/Issue/page/1656/
#define INF 0x3fffffff
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> inpu(101), mat;

int main() {
    for (int i = 0; getline(cin, inpu[i]); i++);

    int maxlen = -INF;
    for (int i = 0; i < inpu.size(); i++) {
        string tmp;
        for (int j = 0; j < inpu[i].size(); j++) {
            if (inpu[i][j] == '#') {
                tmp += '#';
            }
        }
        if (tmp != "") {
            mat.push_back(tmp);
        }
        maxlen = max(maxlen, int(tmp.length()));
    }

    int res = max(int(mat.size()), maxlen);
    res == 0 ? cout << -1 : cout << res;
    
    return 0;
}