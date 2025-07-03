#include <gtest/gtest.h>
/*
    给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序
    的方式存储的，并且每个节点只能存储 一位 数字。
    请你将两个数相加，并以相同形式返回一个表示和的链表。
    你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
    输入：l1 = [2,4,3], l2 = [5,6,4]
    输出：[7,0,8]
    解释：342 + 465 = 807.
*/
using namespace std;

struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void freeList(ListNode* head)
{
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int       carry = 0;
        ListNode  dummy(0);
        ListNode* curr = &dummy;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        return dummy.next;
    }
};

bool listEqual(ListNode* l1, ListNode* l2)
{
    while (l1 && l2) {
        if (l1->val != l2->val)
            return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == nullptr && l2 == nullptr;
}

TEST(LeetCodeTest, test1)
{
    Solution  sol;
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* expect = new ListNode(7, new ListNode(0, new ListNode(8)));

    ListNode* res = sol.addTwoNumbers(l1, l2);

    EXPECT_TRUE(listEqual(res, expect));

    freeList(l1);
    freeList(l2);
}