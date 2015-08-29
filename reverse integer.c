本题的难点是，溢出的处理。
注意，c++中int long 都是32位的，long long 是64位的

亮点1：数字转成字符串
亮点2：字符串转成数字

class Solution {
public:
	int reverse(int x) {

		int tmp = x;
		bool flag = false;//正数
		if (tmp < 0)//化为正数处理
		{
			tmp = 0 - tmp;
			flag = true;
		}

		char num[32] = {'\0'};
		int index = 0;
		while (tmp)//把数字转成字符串
		{
			num[index++] = (tmp % 10) + 48;
			tmp = tmp / 10;
		}

		int len = strlen(num);
		long long ret = 0;
		for (int i = 0; i < len; ++i)//把字符串转成数字
		{
			ret = ret*10 + (num[i]-48);
		}
		
		if (ret > 0x7fffffff)//判断溢出
			ret = 0;
		if (flag)
			ret = 0 - ret;
		
		return (int)ret;
	}
};