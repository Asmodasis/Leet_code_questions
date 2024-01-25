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
        ListNode* tempNode = new ListNode(0);
        ListNode* currentNode = tempNode;
        
        int carry = 0;

        while(l1 !=  nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            // not at end of l1
            if(l1 != nullptr){
                // traverse l1 and add values
                sum += l1->val;
                l1 = l1->next;
            }

            // not at end of l2
            if(l2 != nullptr){
                // traverse l2 and add values
                sum += l2->val;
                l2 = l2->next;
            }
            // unpack each powers of 10
            currentNode->next = new ListNode(sum % 10);
            carry = sum / 10;
            // traverse the tree
            currentNode = currentNode->next;
        }
        return tempNode->next;
    }
};