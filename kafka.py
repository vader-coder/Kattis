#https://open.kattis.com/problems/kafkaesque

sigs = int(input())
count = 1
last = 0

for i in range(sigs):
    desk = int(input())
    if (desk < last):
        count += 1
    last = desk
print(count)