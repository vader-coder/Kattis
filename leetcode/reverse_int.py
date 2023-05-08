class Solution:
    def reverse(self, x: int) -> int:
        if x < 0:
            z = x*-1
            z = int(f"{z}"[::-1])*-1
            if z.bit_length() > 32:
                return 0
            return z
        z = int(f"{x}"[::-1])
        if z.bit_length() > 32:
            return 0
        return z

print(Solution.reverse(Solution, 429496795))