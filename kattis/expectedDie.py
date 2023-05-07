#try to solve this problem by calculating expected value

def sumOneToN(n):
    return float(n*(n+1)/2)

def expectedValueOneDie():
    return float(sumOneToN(6))*1/6

def expectedValueNDie(n, expectedOne):
    return n*expectedOne

def kWithMaxProbability(dice, target):
    expectedOne = expectedValueOneDie()
    target = float(target)
    difference = abs(target-expectedValueNDie(1, expectedOne))
    probabilities = {difference: 1}
    probList = [difference]
    i = 2
    while (i<=dice):
        result = abs(target-expectedValueNDie(i, expectedOne))
        probList.append(result)
        probabilities[result] = i
        i+=1
    print(probList)
    print(probabilities)
    return probabilities[min(probList)]#min difference between expected and target

print(kWithMaxProbability(3, 9))
print(kWithMaxProbability(4, 13))
