// https://www.noobdream.com/DreamJudge/Issue/page/1559/
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string x, t, ins;
    getline (cin, x);
    int n, l, r;
    cin >> n;
    while (n--) {
        cin >> ins;
        if (ins == "CUT" || ins == "COPY") {
            scanf("%d %d", &l, &r);
            t = x.substr(l, r - l + 1);
            if (ins == "CUT") {
                x.erase(l, r - l + 1);
            }
        } else if (ins == "PASTE") {
            int p;
            scanf("%d", &p);
            x.insert(p + 1, t);
        } else exit(-1);

        cout << x << "\n";
    }
    return 0;
}