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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        int size = 0; 
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            size++;
        }

        int groupSize = (size/k);
        int extra = size%k;
        
        ListNode * prev = NULL;
        ListNode * curr = head;
        vector<ListNode *> ans(k , NULL);
        
        for(int i = 0 ; i<size && curr ; i++ ){
            ans[i]=(curr);
            
            int range = groupSize;
            if(extra>0){
                range++;
                extra--;
            }
            
            //isse apan next group ke first bande pe gaye
            for(int j = 0 ; j<range ; j++){
                prev = curr;
                curr = curr->next;
            }
            
            //now the unlinking part
            prev->next = NULL;
        }

        return ans;

    }
};