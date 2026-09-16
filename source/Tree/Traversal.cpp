void dfs_recursion(TreeNode* cur){ // pre, in, post
    if(cur == nullptr) return;

    // do something here: preorder
    dfs_recursion(cur->left);
    // do something here: inorder
    dfs_recursion(cur->right);
    // do something here: postorder
}

void dfs_stack(TreeNode* root){ // pre
    stack<TreeNode*> st;
    if(root == nullptr) return;
    st.push(root);
    while(!st.empty()){
        TreeNode* cur = st.top();
        st.pop();

        // can only do something here: preorder

        if(cur->right != nullptr) st.push(cur->right); // 注意後進先出，所以right晚出要先push
        if(cur->left != nullptr) st.push(cur->left);
    }
}

void bfs_queue(TreeNode* root){ // level
    queue<TreeNode*> q;
    if(root == nullptr) return;
    q.push(root);
    while(!q.empty()){
        TreeNode* cur = q.front();
        q.pop();

        if(cur->left != nullptr) q.push(cur->left);
        if(cur->right != nullptr) q.push(cur->right);
        // do something anywhere will still be level ordered
    }
}

/*
題意：給定 preorder 與 inorder 的序列，輸出 postorder 長甚麼樣子
*/
void solve(string pre, string in){ // preorder, inorder
    if(pre.empty() || in.empty()) return;
    char root = pre[0]; // pre order的第一個值就是root
    int in_idx_root = in.find(root); // 去找inorder的root的位置,就可以得到左右子樹的分割點

    string in_left = in.substr(0, in_idx_root);
    string in_right = in.substr(in_idx_root+1);

    string pre_left = pre.substr(1, in_idx_root);
    string pre_right = pre.substr(in_idx_root+1);

    solve(pre_left, in_left);
    solve(pre_right, in_right);
    printf("%c", root); // postorder
}