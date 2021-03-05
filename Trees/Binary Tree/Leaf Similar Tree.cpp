class Solution {
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2)
	{
		vector<int> leaf1, leaf2;
		
        constructLeafSequence(root1, leaf1);
		constructLeafSequence(root2, leaf2);
		
        if(leaf1.size() != leaf2.size())
            return 0;
        
        for (int i = 0; i < leaf1.size(); i++)
		{
			if (leaf1[i] != leaf2[i])
			{
				return 0;
				break;
			}
		}
		return 1;
	}
	void constructLeafSequence(TreeNode* root, std::vector<int>& leaf)
	{
		if (root == NULL)
			return;
		if (root->left == NULL && root->right == NULL)
			leaf.push_back(root->val);
		constructLeafSequence(root->left, leaf);
		constructLeafSequence(root->right, leaf);
	}
};
