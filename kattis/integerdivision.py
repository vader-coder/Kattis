import math

def uniquePairs(itemsInSet):
    n = itemsInSet
    return n*(n-1)/2

def divide(dividend, divisor):
    if (dividend % divisor):
        return int(math.floor(float(dividend)/float(divisor)))
        #c++ division
    else:
        return dividend/divisor

line1 = input().split(' ')
integerNum = int(line1[0])
divisor = int(line1[1])
integers = list(map(int, input().split(' ')))
quotients = []
distinctQuotients = []
quotientTimesDict = dict()#maps quotient to how many times it exists
#test_list = list(map(int, test_list))
for integer in integers:
    quotients.append(divide(integer, divisor))

for quotient in quotients:
    if quotient in quotientTimesDict:
        quotientTimesDict[quotient]+=1
    else:#doesn't exist
        quotientTimesDict[quotient] = 1
        distinctQuotients.append(quotient)
pairs = 0
for quotient in distinctQuotients:
    indeciesNum = quotientTimesDict[quotient]
    pairs += uniquePairs(indeciesNum)
print(int(pairs))