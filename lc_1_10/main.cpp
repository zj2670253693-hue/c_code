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
int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> res = towSum(nums,target);
    for (int i = 0;i<res.size();i++) {
        cout << res[i] << " ";
    }

    return 0;
}