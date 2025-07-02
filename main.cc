#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;  

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hashmap.find(complement) != hashmap.end()) {
                return {hashmap[complement], i};
            }
            hashmap[nums[i]] = i;
        }
        return {};
    }
};

TEST(LeetCodeTest, test1) {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);

    vector<int> expected = {0, 1}; // 正确答案是下标
    EXPECT_EQ(result, expected);
}