/*
    Method only submission    
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        // dont do anything if list has less than 2 nodes
        if(head == nullptr || head->next == nullptr)
            return head;
            
        // save pointer to first even node
        ListNode* evenStart = head->next;
            
        // obtain pointers to first odd (o) and first even (e) number    
        ListNode *o = head, *e = head->next;    
        
        // repeat while e and e's next node are not null
        while(e!=nullptr && e->next!=nullptr){
            
            o->next = e->next;      // set o's next to e's next
            o = o->next;            // set o as o's next
            e->next = o->next;      // set e's next as o's next
            e = e->next;            // set e as e's next
        }
        
        o->next = evenStart;        // point last odd node's next to first even node
        
        return head;                // return head
        
    }
};