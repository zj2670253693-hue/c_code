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
int n;
int temp[N];
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
void quick_sort(int q[],int l,int r) {
    if (r <= l) return;
    int i = l -1,j = r+1,x = q[l];
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) {
            swap(q[i],q[j]);
        }
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}
// 归并排序

void marge_sort(int q[],int l,int r) {
    if (r <= l) return;
    int mid = r + l >> 1;
    marge_sort(q,l,mid);
    marge_sort(q,mid+1,r);
    int i = l,j = mid+1,k = 0;
    while (i <= mid && j <= r) {
        if (q[i] < q[j])
            temp[k++] = q[i++];
        else
            temp[k++] = q[j++];
    }
    while (i<=mid) temp[k++] = q[i++];
    while (j<=r) temp[k++] = q[j++];
    // 复制回原来的数组
    for (i = l,j = 0;i<=r;i++,j++) {
        q[i] = temp[j];
    }
}
// 整数二分
// 浮点数二分
void marge_sort_1(int q[],int l,int r) {
    if (l >= r ) {
        return;
    }
    int mid = (l + r) >> 1;
    marge_sort_1(q,l,mid);
    marge_sort_1(q,mid+1,r);
    int i = l,k = 0,j = mid+1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) {
            temp[k++] = q[i++];
        }else {
            temp[k++] = q[j++];
        }
    }
    // 剩余的
    while (i <= mid) {
        temp[k++] = q[i++];
    }
    while (j <= r) {
        temp[k++] = q[j++];
    }
    // 把临时temp赋值到q中
    for (i = l,j = 0;i <= r;i++,j++) {
        q[i] = temp[j];
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    marge_sort(q,0,n-1);
    for (int i = 0; i < n; i++) {
        cout << q[i] << " ";
    }
    // quick_sort(q,0,n-1);5
    // for (int i = 0; i < n; i++) {
    //     cout << q[i] << " ";
    // }
    // cout << quick_select(0,n-1,k);
    // vector<int> nums = {2,7,11,15};
    // int target = 9;
    // vector<int> res = towSum(nums,target);
    // for (int i = 0;i<res.size();i++) {
    //     cout << res[i] << " ";
    // }

    return 0;
}