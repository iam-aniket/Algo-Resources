string tree2str(TreeNode* t)
{
	if (NULL == t) return "";

	string str(to_string(t->val));

	string lstr = tree2str(t->left);
	string rstr = tree2str(t->right);

	if (!lstr.empty() || !rstr.empty())
	{
		str += "(" + lstr + ")";
	}
	if (!rstr.empty())
	{
		str += "(" + rstr + ")";
	}

	return str;
}
