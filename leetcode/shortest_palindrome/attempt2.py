class Solution:
    def longestPalindrome(self, s:str) -> int:
        T = [{(0,0):1}, {}] # T[0] is previous, T[1] is current
        print(f"T[0] {sorted(T[0].keys(), key=lambda x : x[0])}")
        for n in range(1, len(s)):
            T[1] = {(n,n):1} # put 1 in current
            c = s[n]
            if c == s[n-1]:
                T[1][(n-1,n)] = 2
            for palindrome in T[0]:
                if palindrome[0] > 0:
                    left = palindrome[0]-1
                    if s[left] == c:
                        length = n-left+1
                        T[1][(left, n)] = length
            print(f"T[{n}] {sorted(T[1].keys(), key=lambda x : x[0])}")
            T[0] = T[1] # set previous to current
        maxRange = max(T[1], key=T[1].get)
        return maxRange[0]
        # T[1] has all palindromes including n. 
    def shortestPalindrome(self, s: str) -> str:
        if len(s) <= 1:
            return s
        s_rev = s[::-1]
        leftIndex = self.longestPalindrome(s_rev)
        if leftIndex <= 0:
            return s
        return s_rev[:leftIndex] + s

string = 'ba'*10 #'a'*40002
soln = Solution()
soln.shortestPalindrome(string)
# print(soln.shortestPalindrome(string))
