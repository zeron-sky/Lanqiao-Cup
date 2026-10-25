// P1102 A-B 数对
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, c;
	// n表示数列的元素个数，c表示差值 
	cin >> n >> c;
	
	// 定义一个动态数组vector，用于存放数列中的数，数组初始大小为n 
	vector<long long> a(n);
	// 定义一个计数表，键为数值，值为该数值的出现次数，用于查询某值出现的次数 
	map<long long, long long> cnt; 
	
	// 依次输入数列中的各个元素
	for(long long i = 0; i < n; i++) {
		// 存放到数组中 
		cin >> a[i];
		// 登记进计数表中 
		if(cnt.count(a[i]) == 0) {
			// 如果此元素是第一次存放，就另开一行，值为0 
			 cnt[a[i]] = 0; 
		} 
		cnt[a[i]]++; 
	}
	
	// 定义一个变量，用于计数：满足 A-B=C 的数对的个数
	long long ans = 0;
	
	for(long long i = 0; i < n; i++) {
		// 统计符合A = B + C的个数 
		ans += cnt[a[i] + c];
	}
	// 最后输出ans
	cout << ans << '\n'; 
}
