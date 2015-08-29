//2015/7/2 tenyee
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.


class Solution {
public:
    bool isPalindrome(int x) {
       //��������false
       if (x < 0)
          return false;
       else if (x < 10)
          return true;
          
       long long reversed = 0;
       
       //��תx �浽 tmp�У�ע��tmp��ֵ���ܻ����x
       int tmp = x;
       while (tmp)
       {
           reversed = reversed*10 + tmp % 10;
           tmp = tmp /10;
       }
       
       return (reversed - x == 0) ? true:false;
       /*
       //�ֱ�Ƚ�reversed �� x�ĸ�λ������Ⱦͷ�����
       int cmp_1,cmp_2;
       while (reversed && x)
       {
           cmp_1 = reversed % 10;
           reversed = reversed / 10;
           cmp_2 = x % 10;
           x = x / 10;
           
           if (cmp_1 != cmp_2)
              return false;
       }
       
       if (!reversed && !x)
           return true;
       else
           return false;*/
    }
};