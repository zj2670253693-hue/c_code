// leetcode_1_10.cpp
#include <bits/stdc++.h>
using namespace std;
vector<int> towSum(vector<int>& nums,int target) {
    unordered_map<int,int> map;
    for (int i=0;i<nums.size();i++) {
        int r = target - nums[i];
        if (map.count(r)) {
            return {map[r],i};
        }

        map[nums[i]] = i;
    }
    return {};
}
// 在一个整形数组中，使用快速选择算法，得到第k个小的数
const int N = 100010;
int q[N];
int n,k;
int quick_select(int l,int r,int k) {
    if (l == r) {
        return q[l];
    }
    int x = q[l],i = l-1,j = r+1;
    while (i < j) {
        while (q[++i] < x);
        while (q[--j] > x);
        if (i < j) {
            swap(q[i],q[j]);
        }
    }
    // 得到sl表示的是基准位小于等于的元素个数
    int sl = j-l+1;
    if (k <= sl) return quick_select(l,j,k);
    // k-sl表示的是最小的第k个数，不在sl区间，在右边的区间，并且在右边数列中是第k-sl最小的
    return quick_select(j+1,r,k-sl);
}
// 快速排序

// 归并排序
// 整数二分
// 浮点数二分
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    cout << quick_select(0,n-1,k);
    // vector<int> nums = {2,7,11,15};
    // int target = 9;
    // vector<int> res = towSum(nums,target);
    // for (int i = 0;i<res.size();i++) {
    //     cout << res[i] << " ";
    // }

    return 0;
}