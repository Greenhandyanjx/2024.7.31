#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0, traget = 0, res = 0;
        for (auto i : nums) {
            sum += abs(i);
        }
        if ((target + sum) % 2 == 1 || sum < abs(target))return 0;
        int left = abs(target + sum) / 2;
        vector<int>dp(10001, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = left; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[left];
    }
};
//class Solution {
//public:
//    int lastStoneWeightII(vector<int>& stones) {
//        int sum = 0, target = 0;
//        for (auto i : stones) {
//            sum += i;
//        }
//        target = sum / 2;
//        vector<int>dp(10001, 0);
//        for (int i = 0; i < stones.size(); i++) {
//            for (int j = target; j >= stones[i]; j--) {
//                if (j - stones[i] >= 0)
//                    dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
//
//            }
//        }
//        return sum - dp[target] - dp[target];
//    }
//};
//class Solution {
//public:
//    bool canPartition(vector<int>& nums) {
//        vector<int>dp(nums.size() + 1, 0);
//        int target = 0, sum = 0;
//        for (auto i : nums) {
//            sum += i;
//        }
//        if (sum % 2 == 1)return false;
//        else target = sum / 2;
//        for (int i = 0; i < nums.size(); i++) {
//            for (int j = target; j >= nums[i]; j--) {
//                if(j-nums[i]>=0)
//                dp[j] = max(dp[j - nums[i]] + nums[i], dp[j]);
//                dp[j] = dp[j];
//            }
//        }
//        if (dp[target] == target)return true;
//        return false;
//    }
//};