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
    ListNode* rotateRight(ListNode* head, int k) {
        
    if(!head||!head->next||k==0)return head;
    int l=0;
    ListNode*temp=head;
        ListNode*t=head;

    while(temp)
    {
        temp=temp->next;
        l++;
    }
if(k%l==0)return head;
    int i=1;
    while(i!=l-k%l&&t)
    {
    i++;

    t=t->next;
    }
    ListNode*p=t->next;
    t->next=NULL;

    ListNode*nh=p;
  if(p){  while(p->next)p=p->next;
    p->next=head;
  }
    return nh;
    }
};