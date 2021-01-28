////////////////////////////////////////////////////////////////////////////
/*                     BFS                      */
class Solution {
public:
	unordered_map<Node*,Node*> temp;
    Node* cloneGraph(Node* node) 
    {
        if (!node) {
            return NULL;
        }
        
        Node* clone = new Node(node->val,{});
        temp[node] = clone;
        queue<Node*> q;
        q.push(node);

        while(!q.empty())
        {
        	Node* cur = q.front();
        	q.pop();

        	for(auto u : cur->neighbors)
        	{
        		if(temp.find(u) == temp.end())
        		{
        			temp[u] = new Node(u->val,{});
        			q.push(u);
        		}
        		temp[cur]->neighbors.push_back(temp[u]);
        	}
        }
        return clone;
    }
};

////////////////////////////////////////////////////////////////////////////
/*                     DFS                      */
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node -> val, {});
            for (Node* neighbor : node -> neighbors) {
                copies[node] -> neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
    }
private:
    unordered_map<Node*, Node*> copies;
};
