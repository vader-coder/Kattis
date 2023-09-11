class Solution:
    def shortestPalindrome(self, s: str) -> str:
        if len(s) <= 1:
            return s
        leftIndex = 0
        rightIndex = len(s)-1
        cutIndex = len(s) # inclusive, which part we are cutting off the end. 
        while rightIndex > leftIndex: # aa, ab, or bab ending. 
          if s[leftIndex] == s[rightIndex]:
            leftIndex += 1
            rightIndex -= 1
          else: 
            leftIndex = 0
            cutIndex = rightIndex
            rightIndex -= 1

        if cutIndex >= len(s):
            return s
        return s[cutIndex:][::-1] + s

import random
# two-pointer solution
"""
string = "a"*40000
string = list(string)
alphabet = list('abcdefghijklmnopqrstuvwxyz')
for i in range(40000):
  string[i] = alphabet[random.randint(0, len(alphabet)-1)]
string = ''.join(string)
"""

# doesn't work here: aacecaaa
# you can't just cut off the part that didn't match in the previous answer. 

string = "cbcdef"
soln = Solution()
soln.shortestPalindrome(string)
print(soln.shortestPalindrome(string))
