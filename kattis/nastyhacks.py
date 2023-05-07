tests = int(input())
output = []
for test in range(tests):
    data = list(map(int, input().split()))
    noAdvertise = data[0]
    advertise = data[1]
    cost = data[2]
    netBenefit = advertise - cost
    if (noAdvertise > netBenefit):
        output.append("do not advertise")
    elif (netBenefit > noAdvertise):
        output.append("advertise")
    elif (netBenefit == noAdvertise):
        output.append("does not matter")

for i in output:
    print(i)