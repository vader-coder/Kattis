tests = int(input())
ans = []
for i in range(tests):
    cities = []
    trips = int(input())
    for j in range(trips):
        city = input()
        if (not(city in cities)):
            cities.append(city)
    ans.append(len(cities))

for i in ans:
    print(i)