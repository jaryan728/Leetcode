/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int l1=0,l2=0;
    // if(!headA->next&&!headB->next&&headA->val==headB->val)return headA;
    ListNode*tempA=headA;
    ListNode*tempB=headB;
    while(headA||headB)
    {
        if(headA)
        {
            l1++;
            headA=headA->next;
        }
        if(headB)
        {
            l2++;
            headB=headB->next;
        }

    }
    cout<<l1<<l2;
    if(l1<l2&&tempB!=NULL)
    {
        while(l1!=l2)
        {
            tempB=tempB->next;
            l2--;
        }
        
    }
    else if(l2<l1&&tempA)
    {
         while(l1!=l2)
         {
            tempA=tempA->next;
            l1--;
         }
    }
    
    while(tempA&&tempB)
    {
        if(tempA==tempB)
        {
            return tempA;
        }
        tempA=tempA->next;
        tempB=tempB->next;
    }
    return NULL;
    }
};