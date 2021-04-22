//Leet Code Add 2 numbers
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
        ListNode* res = NULL;int sum=0,carry =0;
        
        while(l1!=NULL && l2!=NULL){
            int total = l1->val + l2->val+carry;
            int sum = total%10;carry = total/10;
            cout << sum << " " << carry << endl;
            ListNode* newNode = new ListNode(sum);
            if (res == NULL){
                res = newNode;
            }
            else{
                ListNode * ptr = res;
                while(ptr->next!=NULL){
                    ptr = ptr->next;
                }
                ptr->next =  newNode;
            }
            sum =0;
            l1 = l1->next;l2= l2->next;
        }
        while (l1!=NULL){
        int total = l1->val + carry;
        sum = total%10;carry = total/10;
        ListNode* newNode = new ListNode(sum);
        cout << sum << " " << carry << endl;
        ListNode * ptr = res;
        while (ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
        l1 = l1->next;
    }
    while (l2!=NULL){
        int total = l2->val + carry;
       sum = total%10;;carry = total/10;
        ListNode* newNode = new ListNode(sum);
        cout << sum << " " << carry << endl;
        ListNode * ptr = res;
        while (ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
        l2 = l2->next;
    }
    if (carry!=0){
        ListNode* newNode = new ListNode(carry);
        ListNode * ptr = res;
        while (ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    return res;
    }
    
};