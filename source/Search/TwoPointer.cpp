// === 對向雙指針 ===
int l = 0, r = n - 1;

while (l < r) {
    if (a[l] + a[r] == target) {
        // 找到 l, r
        break;
    }
    else if (a[l] + a[r] < target)
        l++;
    else
        r--;
}

// === 同向雙指針 ===
int i = 0, j = 0;

while (i < n && j < m) {
    if (A[i] < B[j]) i++;
    else j++;
}

// === 快慢雙指針 ===
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
        break;
}