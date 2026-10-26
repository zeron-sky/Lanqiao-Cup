// P5266 【深基17.例6】学籍管理
// 用 map 做键值映射，键为姓名，值为分数

#include<bits/stdc++.h>
using namespace std;

int main() {
	// 操作条数
	int q;
	cin >> q;

	// 姓名 -> 分数，底层是平衡树，单次查找 O(log n)
	map<string, int> mp;

	while(q--) {
		// 本次操作的类型
		int op;
		cin >> op;

		// 1 录入  2 查询  3 删除  4 统计人数
		if(op == 1) {
			// 读入姓名与分数
			string s;
			int score;
			cin >> s >> score;

			// operator[] 本身就能插入或覆盖，同名以最新分数为准
			mp[s] = score;
			cout << "OK" << '\n';
		}

		if(op == 2) {
			// 按姓名查找
			string s;
			cin >> s;
			auto it = mp.find(s);
			if(it != mp.end()) {
				// 命中，second 即对应分数
				cout << it->second << '\n';
			} else {
				// 未命中，表里没有这条记录
				cout << "Not found" << '\n';
			}
		}

		if(op == 3) {
			// 按姓名删除
			string s;
			cin >> s;
			auto it = mp.find(s);
			if(it != mp.end()) {
				// 迭代器已经拿到，直接 erase，省一次按键查找
				mp.erase(it);
				cout << "Deleted successfully" << '\n';
			} else {
				// 记录不存在，自然删不掉
				cout << "Not found" << '\n';
			}
		}

		if(op == 4) {
			// 当前记录条数
			cout << mp.size() << '\n';
		}
	}
	return 0;
}
