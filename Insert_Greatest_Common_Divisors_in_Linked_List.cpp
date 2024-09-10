//Iterative Approach
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        //Iterative Approach TC is O(n) and Sc is O(1)
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode * curr = head;
        ListNode * nextNode = head->next;
        while(curr->next != NULL){
            ListNode* gcd = new ListNode(__gcd(curr->val, nextNode->val));
            curr->next = gcd;
            gcd->next = nextNode;

            curr=nextNode;
            nextNode= nextNode->next;
        }
        return head;
    }
};

//Recursive Approach Tc is O(n) and Sc is O(n) as recursion stack space
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode * temp = insertGreatestCommonDivisors(head->next); //Leap of faith
        ListNode* gcd = new ListNode (__gcd(head->val, head->next->val));
        head->next = gcd;
        gcd ->next = temp;
        return head;
    }
};
