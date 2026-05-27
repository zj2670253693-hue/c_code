// leetcode_1_10.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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
}
int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> res = towSum(nums,target);
    for (int i = 0;i<res.size();i++) {
        cout << res[i] << " ";
    }
    return 0;
}