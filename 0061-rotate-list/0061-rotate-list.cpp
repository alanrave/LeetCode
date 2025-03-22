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
ListNode *getkthNode(ListNode *temp,int k)
{
     k-=1;
   while(temp!=NULL&&k>0)
    {
        temp=temp->next;
        k--;
    }
    return temp;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||k==0)
        return head;
        int len=1;
        ListNode *tail=head;
        while(tail->next!=NULL)
        {
            len++;
            tail=tail->next;
        }
        if(k%len==0)
        {
            return head;
        }
        k=k%len;
        int d=len-k;
        ListNode *newLastNode=getkthNode(head,d);
        tail->next=head;
        head=newLastNode->next;
        newLastNode->next=NULL;
        
        return head;
    }
};