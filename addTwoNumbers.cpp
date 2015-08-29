/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //把两条链合成一条l1，返回
        ListNode *p1, *p2, *pre;
        int sum = 0;
		int add = 0;
        p1 = l1;
        p2 = l2;
        pre = p1;
		if (!l1)
			return l2;
		if (!l2)
			return l1;
		
        while ( p1 && p2 )
		{
			sum = p1->val + p2->val + add;
			p1->val = sum % 10;
			add = sum / 10;
			pre = p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		
		if ( !p1 && !p2 )
		{
			if (add)
			{
				ListNode* node = new ListNode(1);
				pre->next = node;
			}
		}
		else if (p1)//p1 不为空
		{
			while (p1)
			{
				sum = p1->val + add;
				p1->val = sum % 10;
				add = sum / 10;
				pre = p1;
				p1 = p1->next;
			}
			if (add)
			{
				ListNode* node = new ListNode(1);
				pre->next = node;
			}
		}
		else//p2不为空
		{
			pre->next = p2;
			
			while (p2)
			{
				sum = p2->val + add;
				p2->val = sum % 10;
				add = sum / 10;
				pre = p2;
				p2 = p2->next;
			}
			if (add)
			{
				ListNode* node = new ListNode(1);
				pre->next = node;
			}
		}
		
		return l1;
    }
};