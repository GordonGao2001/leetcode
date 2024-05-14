#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::cin;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 struct ListNode {
     int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0,new ListNode(0));
        ListNode* res = dummy;
        ListNode* l1ptr= l1;
        ListNode* l2ptr = l2;
        bool l1_exit = l1 != nullptr;
        bool l2_exit = l2 != nullptr;
        int tempval = 0;
        while(l1_exit || l2_exit)
        {
            res->next = new ListNode(tempval/10);
            res = res->next;
            tempval = res -> val;
            int l1_val = 0;
            int l2_val = 0;
            if(l1_exit)
            {    
                l1_val = l1ptr->val;
                tempval = tempval + l1_val;
                l1ptr = l1ptr -> next;
                l1_exit = l1ptr != nullptr;
            }
            if(l2_exit)
            {
                l2_val = l2ptr->val;
                tempval = tempval + l2_val;
                l2ptr = l2ptr -> next;
                l2_exit = l2ptr != nullptr;
            }  
            res->val = tempval%10;
            
        }
        res->next = tempval > 9? new ListNode(tempval/10):nullptr;;
        return dummy->next;

    }
};

int main(int argc, const char * argv[])
{
    Solution s;
    ListNode* l1 = new ListNode(2,new ListNode(4,new ListNode(3)));
    ListNode* l2 = new ListNode(5,new ListNode(6,new  ListNode(4)));
    ListNode* res = s.addTwoNumbers(l1,l2);
    while(res != nullptr)
    {    cout<< res->val<<'\t';
        res = res->next;
    }
    return 0;
}