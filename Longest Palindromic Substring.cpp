//Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.


class Solution {
public:
	string longestPalindrome(string s) {
     
	 if (s.empty())
		 return "";
	 if (s.size() == 1)
		 return s;
	
	  int i = 0,min_start = 0, max_len = 1;
	  while ( i < s.size() )
	  {
		  if (s.size() - i <= max_len / 2)
			  break;
		  
		  int j = i, k = i;
		  while (k < s.size()-1 && s[k+1] == s[k])//跳过相同的字母
			  ++k;
		  i = k+1;//i 是 遍历下标
		  while (k < s.size()-1 && j > 0 && s[k+1] == s[j-1])
		  {
			  ++k;
			  --j;
		  }
		  
		  int new_len = k - j + 1;
		  if (new_len > max_len)
		  {
			  min_start = j;
			  max_len = new_len;
		  }
	  }
	  return s.substr(min_start, max_len);
    }
	
class Solution {
public:
	string longestPalindrome(string s) {

		if (s.empty() || s.size() == 1)
			return s;

		int minStart = 0;
		int maxlength = 0;
		int i = 0;
		//while (i < s.size())
		for (; i < s.size();)
		{
			if (maxlength / 2 >= s.size() - i)//计算回文长度，减少运算
				break;
			//记录头与尾下标
			int pStart = i, pEnd = i;
			//跳过所有相同元素,注意到，如果从当前位置开始没有连续相同的元素，则pStart == pEnd;
			while (pEnd < s.size()-1 && s[pEnd] == s[pEnd+1])
				++pEnd;
			//更新 i
			i = pEnd + 1;//只能在此更新i的值，而不是用下面的pEnd去更新i的值，因为后面可能还有更长的回文
			//扩展回文
			while (pStart > 0 && pEnd < s.size()-1 && s[pStart-1] == s[pEnd+1])
			{
				++pEnd;
				--pStart;
			}

			//计算新的长度
			int newLength = pEnd - pStart + 1;
			if (newLength > maxlength)
			{
				maxlength = newLength;
				minStart = pStart;
			}

		}
		return s.substr(minStart, maxlength);
	}
};

