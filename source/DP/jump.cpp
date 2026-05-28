/*
題目出處: PUPC 2025 PC River Crossing
題目敘述: 給定一組陣列，1表示可達，0表示不可達，問你最少需要跳幾次可以跳到終點，以及跳時經過的路徑
如果不需要輸出路徑，可以直接用greedy，但要輸出路徑就需要用DP
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int kase;
	cin >> kase;
	while(kase--){
		int n;
		cin >> n;
		vector<int> v(n), ans(n, 0x3f3f3f3f), pre(n, -1); 
// v 存原始陣列, ans存抵達該格的最短步數, pre存 在最短步數的情況下，我上一格走的位置
		for(int i=0; i<n; ++i) cin >> v[i]; // 讀入陣列
		ans[0] = 0; // 初始化: 跳到第0格的距離是0
		for(int i=1; i<n; ++i){ // 接下來每次遍例我的前三格
			if(v[i] == 0) continue; // 如果該格不可達，
			for(int j=1; j<=3; ++j){ // 這裡的3是題目設定的，請改成該題目設置的數值
				if(i-j >= 0 && v[i-j] == 1 && ans[i-j] != 0x3f3f3f3f){
// 判斷: 1. 在邊界內， 2. 該格可走， 3. 重複確認該格可走(如不可走，ans[i-j]會直接skip，保留INF)
					if(ans[i] >= ans[i-j] + 1){ // 注意題目要求: 相同距離的情況下，格子要選哪一個，在這題中紀錄的格子要越小越好
						ans[i] = ans[i-j]+1;
						pre[i] = i-j;
					}
				}
			}
		}
		if(ans[n-1] == 0x3f3f3f3f) cout << -1 << '\n';
		else{
			cout << ans[n-1] << '\n';
			
			int i = n-1;
			stack<int> st;
			st.push(n-1);
			while(i > 0){
				st.push(pre[i]);
				i = pre[i];
			}

            bool first = true;
			while(!st.empty()){
				if(!first) cout << ' ';
				first = false;
				cout << st.top();
				st.pop();
			}
			cout << '\n';
		}
	}
	return 0;
}