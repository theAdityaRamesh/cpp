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

    deque<int> minHeap;
    deque<int> track;
    void minHeapify(int i, int left, int right, int heapSize){
            
        int smallest = i;
        
            if(left < heapSize && minHeap[i] > minHeap[left] ){
                smallest = left;
            } 

            if(right < heapSize && minHeap[right] < minHeap[smallest]){
                smallest = right;
            }

                
            if(smallest != i){
                swap(minHeap[i], minHeap[smallest]);
                swap(track[i], track[smallest]);
                
                minHeapify(smallest, 2*i+1, 2*i+2, heapSize);
            }            
        } 
    

    
    ListNode* addNode(ListNode* last, int num){
        ListNode* node = new ListNode;
        node->val = num;
        node->next = nullptr;
        last->next = node;

        return node;
    }
    
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        

        if(lists.size()==0){
            return NULL;
        }
        
        if(lists.size() == 1 && lists[0] == NULL){
            return NULL;
        }
        
        
        ListNode* listPtr;
        int heapSize = minHeap.size();
        
        for (int i = 0; i < lists.size(); i++){
            listPtr = lists[i];
            
            if(listPtr == nullptr){
                continue;
            }
            
            // add the heads of the k lists
            // to the minHeap
            minHeap.push_back(listPtr->val);
            track.push_back(i);
        }
        
        // min heapify min heap made of
        // heads of k linked lists
        heapSize = minHeap.size();
        for(int i = heapSize/2; i >= 0 ; i--){
            minHeapify(i,2*i+1,2*i+2, heapSize);
        }
       
        ListNode* head = new ListNode;
        head->val = -1;
        head->next = nullptr;
        ListNode* last = head;
        
        int root = 0;
        int listNum = 0;
        while(minHeap.size() != 0){
            
            
            root = minHeap[0]; //extract root
            listNum = track[0]; // track keeps track of which list the root belonged to
            lists[listNum] = lists[listNum]->next; // delete head and move it to next node
            
            minHeap.pop_front();
            track.pop_front();           
            
            // added root to result list
            last = addNode(last, root);
            if(lists[listNum] != nullptr){
                minHeap.push_back(lists[listNum]->val);
                track.push_back(listNum);
            }          
            
            heapSize = minHeap.size();
            for(int i = heapSize/2; i >= 0 ; i--){
                minHeapify(i,2*i+1,2*i+2, heapSize);
            }
        }
        
        head = head->next;
        return head;
    }
};
