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
        ListNode* ptr1 = head;
        ListNode* tail = head;
        int size = 1;
        while (tail->next != NULL) {
            tail = tail->next;
            size++;
        }
        if ((tail == head) && (n==1)) {
            free(head);
            head = NULL;
            return head;
        }
        ListNode* ptr3 = head;
        if (n == 1) {
            while (ptr3->next != tail) {
                ptr3 = ptr3->next;
            }
            ptr3->next = NULL;
            free(tail);
            tail = ptr3;
            return head;
        }
        int b_index = size-n;
         ListNode* ptr4 = head;
        for (int i =0; i < b_index; i++) {
            if (i > 0) {
                ptr4 = ptr4->next;
            }
            ptr3 = ptr3->next;
        }
        if(ptr3 == head) {
            head = head->next;
            free(ptr3);
            return head;
        }
        ptr4->next = ptr3->next;
        free(ptr3);
        return head;
    }
};
