#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = 1;
        int max_len = 0;
        sort(nums.begin(), nums.end());
        if (nums.size() > 1)
        {
            for (unsigned int i = 1; i < nums.size(); ++i)
            {
                int dif = nums[i] - nums[i - 1];
                if (dif == 1)
                {
                    len++;
                }
                else if (dif == 0)
                {

                }
                else
                {
                    len = 1;
                }
                max_len = max(max_len, len);
            }
            return max_len;
        }
        else if (nums.size() == 1)
            return 1;
        else
            return 0;

    }
};

TEST(LeetCode, example1)
{
    Solution sol;
    vector<int> nums = {100,4,200,1,3,2};
    int expect = 4;
    EXPECT_EQ(sol.longestConsecutive(nums), expect);
}

TEST(LeetCode, example2)
{
    Solution sol;
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    int expect = 9;
    EXPECT_EQ(sol.longestConsecutive(nums), expect);
}

TEST(LeetCode, example3)
{
    Solution sol;
    vector<int> nums = {1,0,1,2};
    int expect = 3;
    EXPECT_EQ(sol.longestConsecutive(nums), expect);
}

TEST(LeetCode, example4)
{
    Solution sol;
    vector<int> nums = {0,0};
    int expect = 1;
    EXPECT_EQ(sol.longestConsecutive(nums), expect);
}