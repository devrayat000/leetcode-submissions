class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0:
            return 0
        
        # ab = abs(x)
        # sign = -1 if ab != x else 1 
        s = str(x)
        neg = 1 if '-' in s else 0
        s = s[neg:][::-1]
        if len(s) > 10:
            return 0
        if neg == 1:
            s = '-' + s
        f = int(s)
        return 0 if f < -2**31 or f > 2**31-1 else f
        