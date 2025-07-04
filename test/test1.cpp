#include <gtest/gtest.h>

/*
    [两数之和]

    给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出
    和为目标值 target  的那 两个 整数，并返回它们的数组下标。

    你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

    你可以按任意顺序返回答案。

    示例 1：
    输入：nums = [2,7,11,15], target = 9
    输出：[0,1]
    解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

    示例 2：
    输入：nums = [3,2,4], target = 6
    输出：[1,2]

    示例 3：
    输入：nums = [3,3], target = 6
    输出：[0,1]


    提示：
        2 <= nums.length <= 104
        -109 <= nums[i] <= 109
        -109 <= target <= 109
        只会存在一个有效答案

    进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？

*/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            if (hashtable.find(target - nums[i]) != hashtable.end()) {
                return {hashtable[target - nums[i]], i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

TEST(LeetCode1, SumofTwoNumbers1)
{
    Solution sol;

    vector<int> nums = {2, 7, 11, 15};
    int         target = 9;
    vector<int> expect = {0, 1};

    EXPECT_EQ(sol.twoSum(nums, target), expect);
}


TEST(LeetCode1, SumofTwoNumbers2)
{
    Solution sol;

    vector<int> nums = {3, 2, 4};
    int         target = 6;
    vector<int> expect = {1, 2};

    EXPECT_EQ(sol.twoSum(nums, target), expect);
}

TEST(LeetCode1, SumofTwoNumbers3)
{
    Solution sol;

    vector<int> nums = {3, 3};
    int         target = 6;
    vector<int> expect = {0, 1};

    EXPECT_EQ(sol.twoSum(nums, target), expect);
}

