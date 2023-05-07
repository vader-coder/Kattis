cost = float(input())
lawns = int(input())
total = 0
for i in range(lawns):
    nums = input().split()
    width = float(nums[0])
    length = float(nums[1])
    total += (width*length*cost)
print(total)