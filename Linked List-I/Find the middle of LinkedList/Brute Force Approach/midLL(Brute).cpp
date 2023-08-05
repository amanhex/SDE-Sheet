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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int length = 0;
        // Finding length of LinkedList
        while (temp){
            length++;
            temp = temp -> next;
        }

        // Finding mid of LinkedList by traversing half of the LinkedList
        temp = head;
        for (int i = 0; i < length / 2; i++)
            temp = temp -> next;
        return temp;
    }
};

// T.C: O(n) + O(n / 2) & S.C: O(1)
