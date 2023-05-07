nums = input().split()
nums[0] = int(nums[0])
nums[1] = int(nums[1])
num = 0
num2 = 0
digit1 = []
digit2 = []
for i in range(2):
    rem = nums[i]%10
    result = 0
    if (i):
        digits = digit1
    else:
        digits = digit2
    while(rem):#loop puts digits into arrays
        digits.append(rem)
        nums[i] = (nums[i]-rem)/10
        rem = nums[i]%10
    count = len(digits)
    length = count
    for j in range(length):#makes numbers
        result += digits[j]*(10**(count-1))
        count-=1
    if (i):
        num = result
    else:
        num2 = result
if (num>num2):
    print(str(nums[0]))
elif(num2>num):
    print(str(nums[1]))