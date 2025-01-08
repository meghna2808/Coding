/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        vector<Node*>cloned(101,NULL);
        if(node==NULL) return NULL;
        cloned[node->val]=new Node(node->val,node->neighbors);
        queue<Node*>q;
        q.push(node);
        while(!q.empty())
        {
            Node* curr=q.front();
            q.pop();
            for(int i=0;i<curr->neighbors.size();i++)
            {
                if(cloned[curr->neighbors[i]->val]==NULL)
                {
                    cloned[curr->neighbors[i]->val]=new Node(curr->neighbors[i]->val,curr->neighbors[i]->neighbors);
                    q.push(curr->neighbors[i]);
                }
                cloned[curr->val]->neighbors[i]=cloned[curr->neighbors[i]->val];
            }
            
        }
        return cloned[node->val];
    }
};