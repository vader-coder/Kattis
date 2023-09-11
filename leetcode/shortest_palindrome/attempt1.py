from collections import deque

class Solution:
    def shortestPalindrome(self, s: str) -> str:
        if len(s) <= 1:
            return s
        s_list = deque(s)
        s_it = iter(s_list)
        reverse_list = deque([])
        largestPalindromeIndex = 0
        for i in range(len(s)):
            reverse_list.appendleft(next(s_it))
            # compare elements
            reverse_it = iter(reverse_list)
            s_it2 = iter(s_list)
            isPalindrome = True
            for j in range(i+1): # i = 0, range(1)
                if next(reverse_it) != next(s_it2):
                    isPalindrome = False
                    break
            if isPalindrome:
                largestPalindromeIndex = i
        if largestPalindromeIndex >= (len(s)-1):# > would be a bug
            return s
        if largestPalindromeIndex < (len(s)-1):
            return s[largestPalindromeIndex+1:][::-1]+s

string = 'a'*4000 #'a'*40002
soln = Solution()
print(soln.shortestPalindrome(string))
