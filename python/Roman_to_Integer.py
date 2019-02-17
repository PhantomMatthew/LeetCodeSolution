class Solution:
    def romanToInt(self, s: 'str') -> 'int':
        d = {'I': 1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        sum = 0
        # for i in range(len(s)):
        #     if i < range(len(s)):
        #         if d[s[i]] <= d[s[i+1]]:
        #             sum += d[s[i]]
        #         else:
        #             sum -= d[s[i]]
        #         sum += d[s[]]
        # return sum

        i = 0
        while i < len(s) - 1:
            if s[i] + s[i+1] in d.values():
                sum += d[s[i] + s[i+1]]
                i += 2
            else:
                sum += d[s[i]]
                i += 1
                
        if i != len(s):
            sum += d[s[len(s) - 1]]
        return sum

solution = Solution()
solution.romanToInt("CM")