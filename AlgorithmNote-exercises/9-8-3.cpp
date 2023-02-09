#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

typedef struct node{
    int weight;
    string words;
    friend bool operator < (node x1, node x2) { 
        // 反向定义'<'，从而构造出小顶堆
        return x1.weight > x2.weight;
    }
    node(){}
    node(int _weight, string _words) {
        weight = _weight;
        words = _words;
    }
} node;

typedef struct info{
    int freq = 0;
    string code = "";
} info;

map<char, info> mp;
priority_queue<node> que; 

int main() {
    // freopen(".\\in.txt", "r", stdin);
    char inpu;
    while (1) {
        inpu = getchar();
        if (inpu == EOF || inpu == '\n') {
            break;
        }
        (mp[inpu].freq)++;
    }

    for (map<char, info>::iterator it = mp.begin(); it != mp.end(); it++) {
        string tmp = "";
        tmp.insert(tmp.end(), it->first);
        que.push(node(it->second.freq, tmp));
    }

    while (!(que.size() == 1)) {
        node x1 = que.top();
        que.pop();
        node x2 = que.top();
        que.pop();

        for (int i = 0; i < x1.words.size(); i++) {
            mp[x1.words[i]].code += "0";
        }
        for (int i = 0; i < x2.words.size(); i++) {
            mp[x2.words[i]].code += "1";
        }

        que.push(node(x1.weight + x2.weight, x1.words + x2.words));
    }

    if (mp.size() == 1) {
        mp.begin()->second.code = "0";
    }

    int res = 0;
    for (map<char, info>::iterator it = mp.begin(); it != mp.end(); it++) {
        res += it->second.code.size() * it->second.freq;
    }

    // 输出该文本对应的最短编码长度
    cout << res;

    // 输出每个字母对应的编码
    // cout << endl;
    // for (map<char, info>::iterator it = mp.begin(); it != mp.end(); it++) {
    //     cout << it->first << ":"<< it->second.code << endl;
    // }
    return 0;
}
