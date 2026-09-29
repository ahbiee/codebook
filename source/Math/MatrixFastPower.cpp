// 基本的矩陣乘法，a的row必等於b的col才能乘
vector<vector<int>> multiply(const vector<vector<int>> &a, const vector<vector<int>> &b) {
	int n = a.size(); // a = n*k
	int m = b[0].size(); // b = k*m
	int k = a[0].size();
	vector<vector<int>> ans(n, vector<int>(m, 0)); // 新矩陣的size為n*m
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int c = 0; c < k; c++) {
                ans[i][j] += a[i][c] * b[c][j]; // 視需求在此取模
            }
        }
    }
    return ans;
}

// 矩陣快速冪，要求矩陣為正方形(n * n)
vector<vector<int>> power(vector<vector<int>> m, int p) {
    int n = m.size(); // m = n*n
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        ans[i][i] = 1; // ans 初始化為 單位矩陣 (I)
    }
    while(p != 0){
        if ((p & 1) != 0) {
            ans = multiply(ans, m);
        }
        m = multiply(m, m);
        p >>= 1;
    }
    return ans;
}