class Solution:
    def romanToInt(self, s: 'str') -> 'int':
        d1 = {'I': 1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        d2 = {'IV':4, 'IX': 9, 'XL':40, 'XC':90, 'CD':400, 'CM': 900}
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
            if s[i] + s[i+1] in d2.values():
                sum += d2[s[i] + s[i+1]]
                i += 2
            else:
                sum += d1[s[i]]
                i += 1
                
        if i != len(s):
            sum += d1[s[len(s) - 1]]
        return sum

solution = Solution()
solution.romanToInt("CM")