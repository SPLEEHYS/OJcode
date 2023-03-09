#include <cassert>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, int> mp = {
    {'0' , 0  }, 
    {'1' , 1  }, 
    {'2' , 2  }, 
    {'3' , 3  }, 
    {'4' , 4  }, 
    {'5' , 5  }, 
    {'6' , 6  }, 
    {'7' , 7  }, 
    {'8' , 8  }, 
    {'9' , 9  }, 
    {'A' , 10 }, 
    {'B' , 11 }, 
    {'C' , 12 }, 
    {'D' , 13 }, 
    {'E' , 14 }, 
    {'F' , 15 }, 
};


int main() {
    string str;
    while (cin >> str) { // 注意：本题没说多组数据之间的分隔符是空格还是换行（似乎是两个都有），因此不能用getline来读
        reverse(str.begin(), str.end());
        str.erase(str.length() -2 , 2);
        
        int res = 0, plus = 0;
        for (int i = 0; i < str.size(); i++) {
            res += mp[str[i]] * int(pow(16.0, 1.0 * i));
        }

        cout << res << '\n';
    }
    return 0;
}