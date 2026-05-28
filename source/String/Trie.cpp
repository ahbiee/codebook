struct Trie {
    // 如果是字元 size=26, 如果是二進制XOR size=2
    int tree[MAXN][size] = {};
    int passed[MAXN] = {};
    int stop[MAXN] = {};
    // 以上陣列的都跳過index 0
    int cnt = 1;
    
    void init(){
      for(int i=1; i<=cnt; ++i){
        for(int j=0; j<size; ++j) tree[i][j] = 0;
        passed[i] = 0;
        stop[i] = 0;
      }
      cnt = 1;
    }
    
    void insert(string word){
      int curr = 1;
      ++passed[curr]; // 經過點，++passed
      for(int i=0, path; i<word.length(); ++i){
        path = word.at(i) - 'a'; // 求出下一個位置的index
        if(tree[curr][path] == 0) tree[curr][path] = ++cnt; // 如果當前位置走到目標位置不存在，就用++cnt的值
        curr = tree[curr][path]; // 繼續往下走
        ++passed[curr]; // 記得經過就要++passed
      }
      ++stop[curr]; // 最後停住的地方要++stop
    }
    
    int search(string word){
      int curr = 1;
      for(int i=0, path; i<word.length(); ++i){
        path = word.at(i) - 'a';
        if(tree[curr][path] == 0) return 0; // 如果從curr往path的路徑不存在，代表搜尋的word不存在
        curr = tree[curr][path]; // 否則繼續往下走
      }
      return stop[curr]; // 最後回傳在curr位置停下(stop)的次數
    }
    
    int prefixNumber(string word){
      int curr = 1;
      for(int i=0, path; i<word.length(); ++i){
        path = word.at(i) - 'a';
        if(tree[curr][path] == 0) return 0;
        curr = tree[curr][path];
      }
      return passed[curr]; // 和search方法一模一樣，只是回傳的對象變成passed
    }
    
    void erase(string word){
      if(search(word) == 0) return; // 如果找不到字就不管他
      int curr = 1;
      --passed[curr];
      for(int i=0, path; i<word.length(); ++i){
        path = word.at(i) - 'a';
        if(--passed[tree[curr][path]] == 0){ // 如果curr往path的路徑上，p值為1，代表後面的東西都不需要了
          tree[curr][path] = 0; // 將curr不再連通path，直接捨棄後面所有的東西(因為都會被減成p==0)
          return;
        }
        curr = tree[curr][path]; // 否則繼續往下走，注意後面不需要再--passed[curr]，因為在if區塊我們已經操作完了
      }
      --stop[curr]; // 最後--stop[curr]
    }
};