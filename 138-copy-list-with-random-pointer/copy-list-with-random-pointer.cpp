/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    unordered_map<Node*,Node*>mpp;
    Node*temp=head;
    while(temp)
    {
        mpp[temp]=new Node(temp->val);
        temp=temp->next;
    }
    Node*h=head;
    while(h)
    {
    if(h->next==NULL)mpp[h]->next=NULL;
    else mpp[h]->next=mpp[h->next];
        if(!h->random)mpp[h]->random=NULL;

   else mpp[h]->random=mpp[h->random];
    h=h->next;

    }
    return mpp[head];
    
    }
};