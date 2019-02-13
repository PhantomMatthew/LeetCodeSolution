

class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        # method #1 wrong
        # rev = 0
        # while x != 0:
        #     pop = x % 10
        #     x /= 10
        #     if (rev > (2**31-1)/10) or (rev == (2**31-1)/10 and pop > 7):
        #         return 0
        #     if (rev < -2**31/10) or (rev == -2**31/10 and pop < -8):
        #         return 0
        # return rev
        
        # method #2
        # s = lambda x: x and [1, -1][x < 0]
        # r = int(str(s(x) * x)[: : -1])
        # return s(x) * r * (r < 2**31 - 1)
        
        # method #3
        result = int(str(abs(x))[::-1])
        if x > 0 and result < 2**31:
            return result
        if x < 0:
            result = -result
            if result > -2**31:
                return result
        return 0


solution = Solution()
print(solution.reverse(-102304))