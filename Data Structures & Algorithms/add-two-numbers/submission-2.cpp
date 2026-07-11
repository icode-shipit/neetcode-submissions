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
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* head= new ListNode((l1->val+l2->val)%10);
        ListNode* temp=head;
        int carry=(l1->val+l2->val)/10;
        temp1=temp1->next; temp2=temp2->next;
        while(temp1!=NULL || temp2!=NULL)
        {
            if(temp1!=NULL && temp2!=NULL)
            {
                int node_val= carry+ temp1->val+ temp2->val;
                carry=node_val/10;
                node_val=node_val%10;
                temp->next=new ListNode(node_val);
                temp=temp->next;
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else if(temp1!=NULL)
            {
                int node_val= carry+ temp1->val;
                temp1=temp1->next;
                temp->next= new ListNode(node_val%10);
                temp=temp->next;
                carry=node_val/10;
            }
            else
            {
                int node_val= carry+ temp2->val;
                temp2=temp2->next;
                temp->next= new ListNode(node_val%10);
                temp=temp->next;
                carry=node_val/10;
            }
        }
        if(carry!=0)
        {
            temp->next= new ListNode(carry);
        }
        return head;
    }
};
