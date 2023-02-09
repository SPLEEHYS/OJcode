#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
using namespace std;


int main() {
    int n, cnt = 0, k = 0, inpu;  
    priority_queue<int> que; 
    priority_queue<int, vector<int>, greater<int>> pre; 
    /*
    k表示当前的中位数是对应第k小的数（k从1开始）
    cnt表示当前已经push了多少个数，因此有关系式：k = (cnt + 1) / 2; 

    que是一个大顶堆，容量始终维持在k，因此堆顶对应的是第k小的数
    pre是一个小顶堆，用于保存从que中pop出去的数，因此堆顶对应的是第k+1小的数（因为pre中的数必大于que中的数）
    */
    cin >> n;
    string ins;
    for (int i = 0; i < n; i++) {
        cin >> ins;
        if (ins == "Push") {
            cnt++;
            k = (cnt + 1) / 2; // 每次push进一个数，k都有可能会变大
                               // 只有当cnt为奇数时，k才会相较于之前+1
            scanf("%d", &inpu);

            que.push(inpu);
            if (cnt % 2 == 1 && !pre.empty()) {
                // 当前push进入的数是第奇数个时，k相较于之前的k会+1，因此相对于之前的k，此时中位数对应的是第k+1小的数，
                // 因此要把新push进来的数以及之前第k+1小的数（位于pre的堆顶）一起push进que，才能求出在push完新元素后，第k+1小的数。
                que.push(pre.top());
                pre.pop();
            }

            while (que.size() > k) { 
                // 维护que的容量始终为k
                pre.push(que.top());
                que.pop();
            }
        } else {
            if (cnt % 2 == 1) {
                printf("%.1f\n", 1.0 * que.top());
            } else {
                printf("%.1f\n", 1.0 * (que.top() + pre.top()) / 2);
            }
        }
    }
    return 0;
}