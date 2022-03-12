/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
Node* copyRandomList(Node* head){
    
    // empty list
    if(!head){
        return nullptr;
    }
    
    // interweave the new and old list
    // oldNode->newNode->oldNode->newNode ...
    Node* temp = head;
    while(temp){
        Node* curr = new Node(temp->val);
        curr->next = temp->next;
        temp->next = curr;
        temp = curr->next;
    }
    
    // oldNode is always prev of new node
    // so get the old node random
    // and connect it to the oldNodeRandomNext
    // as oldNodeRandomNext is newNode
    temp = head;
    while(temp->next->next){
        if(temp->random != nullptr){
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }
    
    // do it once more for the last node
    if(temp->random){
         temp->next->random = temp->random->next;
    }
    
    // restore the original connections
    // de interlace the old and new list
    temp = head;
    Node* newH = head->next;
    while(temp->next->next){
        Node* oldNext = temp->next->next;
        temp->next->next = oldNext->next;
        temp->next = oldNext;
        temp = oldNext;
    }
    
    temp->next->next = nullptr;
    temp->next = nullptr;
    return newH;
}
};

    Node* copyRandomList(Node* head) {
         // if empty list 
        if(!head){
            return nullptr;
        }
        
        unordered_map<Node*,int> nodeMap;
        Node* temp = head;
        vector<Node*> list;
        int indx = 0;
        while(temp){
            nodeMap.insert({temp, indx++});
            Node* curr = new Node(temp->val);
            curr->next = nullptr;
            curr->random = nullptr;
            list.push_back(curr);
            temp = temp->next;
        }
        
        indx = 0;
        while(head){
            if(head->random != nullptr){
                int rIndx = nodeMap[head->random];
                list[indx]->random = list[rIndx];
            }
            if(indx+1 < list.size()){
                list[indx]->next = list[indx+1];
            }
            indx++;
            head = head->next;
        }
        
        
        return list[0];
}
