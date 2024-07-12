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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     ListNode*ans=new ListNode(0);
     ListNode*temp=ans;
     int carry=0;
     while(l1||l2)
     {
        int s=0;
        if(l1)
        {s+=l1->val;
                l1=l1->next;

        }
        if(l2)
        {s+=l2->val;
                l2=l2->next;

        }s+=carry;
        temp->next=new ListNode(s%10);
        temp=temp->next;
        carry=s/10;

     }
     if(carry)temp->next=new ListNode(carry);
     return ans->next;
    }
};