// P1918 保龄球
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    // 位置数
    int n;
    cin >> n;

    // 存储 瓶子数 -> 位置编号 的对应关系
    map<ll, ll> pos;

    // 逐个读入每个位置的瓶子数，记入表中
    for (int i = 1; i <= n; i++) {
        // 该位置的瓶子数
        ll cnt;
        cin >> cnt;
        // 瓶子数 cnt 对应位置 i，位置从 1 数起
        pos[cnt] = i;
    }

    // 发球次数
    int q;
    cin >> q;

    // 处理每次询问
    while (q--) {
        // 想打倒的瓶子数
        ll m;
        cin >> m;
        // 在表中查找瓶子数等于 m 的记录
        auto it = pos.find(m);
        if (it != pos.end()) {
            // 找到了，输出对应的位置编号
            cout << it->second << '\n';
        } else {
            // 没找到，输出 0
            cout << 0 << '\n';
        }
    }
    return 0;
}
