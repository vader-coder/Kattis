nums = input().split()
cities = int(nums[0])
roads = int(nums[1])
flights = int(nums[2])
startCity = int(nums[3])
endCity = int(nums[4])
roadList = []
flightList = []
for i in range(roads):
    roadList.append(list(map(int, input().split())))

for i in range(flights):
    flightList.append(list(map(int, input().split())))
