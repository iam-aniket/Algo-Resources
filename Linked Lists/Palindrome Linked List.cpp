//O(n) + O(1) approach - VVI

class Solution {
public:
	//Compare Reversed first half == Second half?
	bool isPalindrome(ListNode* head)
	{
		ListNode *pre = NULL, *slow = head, *fast = head;
		//Reverse first half and find middle
		while (fast != NULL && fast->next)
		{
			fast = fast->next->next;
			ListNode *temp = slow;
			slow = slow->next;
			temp->next = pre;
			pre = temp;
		}
		//If fast is not NULL means odd length palindrome
		//so skip center value
		if (fast != NULL)
			slow = slow->next;
		//Compare new first (rev) and second halfs
		while (pre && slow)
		{
			if (pre->val != slow->val)
				return 0;
			pre = pre->next;
			slow = slow->next;
		}
		return 1;
	}
};
