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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 1;
        for(ListNode* ptr = head; ptr->next != nullptr; ptr = ptr->next){
            count++;
        }
        if(head == nullptr || n <= 0 || n > count){
            return head;
        }
        if(n == count){
            ListNode* removed = head;
            head = head->next;
            delete removed;
            return head;
        }
        ListNode* ptr = head;
        for(int i = 0; i < (count - n - 1); i++){
            ptr = ptr->next;
        }
        ListNode* temp = ptr->next;
        ptr->next = ptr->next->next;

        delete temp;
        return head;
    }
};
