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
class Solution {
public:
    ListNode*reverse(ListNode*head)
    {
        ListNode*p=NULL;
        while(head)
        {
            ListNode*n=head->next;
            head->next=p;
            p=head;
            head=n;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
    ListNode*temp=head;
    ListNode*slow=head;
    ListNode*fast=head;
    if(!head->next||!head)return true;
    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode*sl=reverse(slow);
    while(sl&&temp)
    {
        if(sl->val!=temp->val)return false;
        sl=sl->next;
        temp=temp->next;
    }
    
    return true;
    }
};