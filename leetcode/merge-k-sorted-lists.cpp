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

    vector<int> minHeap;
    vector<int> track;
    int heapSize = 0;
    
    void minHeapify(int i, int left, int right){
            
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
                
                minHeapify(smallest,2*i+2 ,2*i+1);
            }            
        } 
       
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        

        if(lists.size()==0){
            return NULL;
        }
        
        if(lists.size() == 1 && lists[0] == NULL){
            return NULL;
        }
        
        
        ListNode* listPtr;
        
        
        for (int i = 0; i < lists.size(); i++){
            listPtr = lists[i];
            
            if(listPtr == nullptr){
                continue;
            }
            
            // add the heads of the k lists
            // to the minHeap
            minHeap.push_back(listPtr->val);
            heapSize++;
            track.push_back(i);
        }
        
        // min heapify min heap made of
        // heads of k linked lists
       
        for(int i = heapSize/2; i >= 0 ; i--){
            minHeapify(i,2*i+2,2*i+1);
        }
       
        ListNode* head = new ListNode;
        head->val = -1;
        head->next = nullptr;
        ListNode* last = head;
        
        int root = 0;
        int listNum = 0;
        while(heapSize != 0){
            
            root = minHeap[0]; //extract root
            listNum = track[0]; // track keeps track of which list the root belonged to
            lists[listNum] = lists[listNum]->next; // delete head and move it to next node     
            
            
            // added root to result list
             ListNode* node = new ListNode;
             node->val = root;
             node->next = nullptr;
             last->next = node;   
             last = node;
            
            if(lists[listNum] != nullptr){
                minHeap[0] = (lists[listNum]->val);
                track[0] = (listNum);
            } else {
                swap(minHeap[0],minHeap[heapSize-1]);
                swap(track[0],track[heapSize-1]);
                heapSize--;  
            }       
            
            for(int i = heapSize/2; i >= 0 ; i--){
                minHeapify(i,2*i+1,2*i+2);
            }
        }
        
        head = head->next;
        return head;
    }
};
