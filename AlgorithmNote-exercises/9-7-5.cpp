/*
求数据流中第K大的数：
    如果是静态数据，只求一次第K大，则用快速划分的方法更快；
    如果是动态数据，多次求第K大，则用该方法更快。
思路：
    求动态数据流的第K大，因此只需要维护一个容量为K的最小堆即可（一旦插入数据后容量大于K，就pop堆顶，使容量保持在K）；
    （相当于随着数据的插入，前K-1大的数据会一直留在堆的底部，而第K大的数据会一直保留在堆顶）
*/

#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<string>
using namespace std;

int n, k;

int main() {
    cin >> n >> k;
    string ins;
    priority_queue<int, vector<int>, greater<int>> heap;

    for (int i = 0; i < n; i++) {
        cin >> ins;
        if (ins == "Push") {
            int inpu;
            scanf("%d", &inpu);
            heap.push(inpu);
            if (heap.size() > k) {
                heap.pop();
            }
        } else {
            if (heap.size() < k) {
                printf("-1\n");
            } else {
                printf("%d\n", heap.top());
            }

        }
    }

    return 0;
}