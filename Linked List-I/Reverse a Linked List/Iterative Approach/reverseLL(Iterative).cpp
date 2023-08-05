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
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = nullptr;
        while (head){
            ListNode* temp = head -> next;
            head -> next = dummy;
            dummy = head;
            head = temp;
        }
        return dummy;
    }
};

// T.C: O(n) & S.C: O(1)
