class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char, int> myMap;
	   string::iterator iter = s.begin();
	   int pre = 0;
	   int next = 0;
	   int index = 0;
	   int maxLength = 0;
	   
	   for (; iter != s.end(); ++iter,index++)
	   {
		   if ( myMap.find(*iter) == myMap.end() )
		   {
			   next = index;
			   myMap[*iter] = index;
			   if (maxLength < next - pre + 1)
				   maxLength = next - pre + 1;
		   }
		   else
		   { 
	          if (myMap[*iter] < pre)
			  {
				  next = index;
				  if (maxLength < next - pre + 1)
				     maxLength = next - pre + 1;
				  myMap[*iter] = index;
			  }
			  
			  else 
			  {
				  next = index;
				  if (maxLength < next - pre)
				     maxLength = next - pre;
				  pre = myMap[*iter] + 1;
				  myMap[*iter] = index;
			  }		   
		   }
	   }
	   
	   
	   return maxLength;
    }
};

//16ms的方法。。。。。Accepted 16ms O(n) c++ solution, with bitmask to record the position of each letter appears
/*
flag[] 存放每个字母出现的位置，而且总是记录最近出现的字母的位置，也就是对于重复出现的，只会保存最近的一次出现的位置
*/
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> flag(256, -1);
        int start = 0, res = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (flag[s[i]] >= start)//表示这个字母再一次出现了
                start = flag[s[i]] + 1;
            flag[s[i]] = i;
            res = std::max(res, i - start + 1);
        }
        return res;
    }
};