int jump(vector<int>& nums) {
    int jumps = 0;        // 總跳躍次數
    int current_end = 0;  // 「當前這一步」能到達的最遠邊界
    int farthest = 0;     // 探索過程中，發現「下一步」能到達的最遠距離
    bool noAns = false;

    // 注意：迴圈只走到 nums.size() - 2
    // 因為如果已經站在最後一個位置，就不需要再起跳了
    for (int i = 0; i < nums.size() - 1; ++i) {
        // 邊走邊看，更新下一跳的最遠潛力
        farthest = max(farthest, i + nums[i]);

        // 當走到了「當前這步」的極限邊界時，就必須結算，進行「下一跳」
        if (i == current_end) {
            if(current_end == farthest){ // 如果被迫跳但發現一步都沒跳就代表走不到終點
                noAns = true;
                break;
            }
            jumps++;
            current_end = farthest; // 將邊界擴展到剛才探索到的最遠距離

            if(current_end >= nums.size()-1) break; // 提前結束的優化
        }
    }
    if(noAns) return -1;
    return jumps;
}