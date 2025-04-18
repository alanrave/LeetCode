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
    ListNode* addTwoNumbers(ListNode* num1, ListNode*num2) {
         ListNode* t1=num1;
    ListNode *t2=num2;
    ListNode *dummyNode=new ListNode(-1);
    ListNode *curr=dummyNode;
    int sum=0,carry=0;
    while(t1!=NULL||t2!=NULL)
    {
          sum=carry;
          if(t1)
          sum+=t1->val;
          if(t2)
          sum+=t2->val;
          ListNode *newNode=new ListNode(sum%10);
          carry=sum/10;
          curr->next=newNode;
          curr=curr->next;
          if(t1) t1=t1->next;
          if(t2) t2=t2->next;
    }
    if(carry)
    {
      ListNode*newNode=new ListNode(carry);
      curr->next=newNode;
    }
    return dummyNode->next;
    }
};