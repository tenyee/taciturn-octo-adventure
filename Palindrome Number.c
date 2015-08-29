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
       //负数返回false
       if (x < 0)
          return false;
       else if (x < 10)
          return true;
          
       long long reversed = 0;
       
       //倒转x 存到 tmp中，注意tmp的值可能会大于x
       int tmp = x;
       while (tmp)
       {
           reversed = reversed*10 + tmp % 10;
           tmp = tmp /10;
       }
       
       return (reversed - x == 0) ? true:false;
       /*
       //分别比较reversed 与 x的各位，都相等就返回真
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