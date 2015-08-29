思想是：
   每numRows+1个元素为一组，计算一共多少组，每一组中的最后一个元素就是中间出现的元素。画个图可以看出来，可以计算出各个元素的坐标，相当于把二维数组拉成一维的样子
   
   ---。---。---。---。--
   如上面的把字串分成5组。
   注意的问题：
   1.可能元素总个数少于numRows+1 或者 只分一行，只有一个元素，可直接返回

class Solution {
public:
	string convert(string s, int numRows) {
		if (1 == numRows || s.size() == 1)
			return s;

		int index=0;
		int N;//the group counts ,each group has (numRows+1) members.
		int strLen = s.size();
		string retStr(strLen + 1, '\0');
		int mid;//middle rows
		if (numRows%2)//odd rows
			mid = numRows / 2;
		else
			mid = numRows / 2 -1;

		N = strLen / (numRows+1);// N may be zero when the size of the string <= numRows 
		if (!N)
			return s;

		if (strLen % N)
			N += 1;

		for (int j = 0; j < numRows; ++j)//j is the offset in the group

		{
			for (int i = 0; i < N; ++i)//i is the offset of the group
			{
				int m = i * (numRows+1) + j;
				if (m < strLen)
				{
					retStr[index++] = s[m];
					if (j == mid)
					{
						int mm = i * (numRows + 1) + numRows;
						if (mm < strLen)
							retStr[index++] = s[mm];
					}
				}
			}
		}

		return retStr;
	}
};