/*
Refer 
https://www.youtube.com/watch?v=h-BhsupJTlE
Kashish Mendiratta channel
*/
class Solution {
public:
	set<Node*> vis;
	map<Node*, Node*> mp;
	Node* cloneGraph(Node* node)
	{
		if (!node)
			return NULL;

		dfs(node, vis, mp);
		addEdges(mp);
		return mp[node];
	}
	void dfs(Node* u, set<Node*>& vis, map<Node*, Node*>& mp) {

//          mark the curr_node visited
		vis.insert(u);

//          make the copy node of u and set the same value as u
		Node* u_copy = new Node(u->val);

//          insert u and u_copy in map
		mp.insert({u, u_copy});

//          traverse through neighbors which are not visited
		for (auto v : u->neighbors) {

//          if v is not traversed
			if (vis.find(v) == vis.end()) {

				// apply the dfs
				dfs(v, vis, mp);
			}
		}
	}

	void addEdges( map<Node*, Node*>& mp) {

//          iterate through map
		for (auto u : mp) {

//          iterate through neighbours
			for (auto v : u.first->neighbors) {

//           add the neighbors to copy node neighbors vector
				u.second->neighbors.push_back(mp[v]);
			}
		}
	}
};
