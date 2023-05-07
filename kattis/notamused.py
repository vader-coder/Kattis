import signal
TIMEOUT = 10#seconds in timeout

def getEntry():
    try:
        entry = input()
        return entry
    except:#return none
        return None

days = []
customersPerDay = []
dayIndex = 0
for day in range(20):
    signal.alarm(TIMEOUT)
    entry = getEntry()#get entry for enter
    if (entry != None):
        signal.alarm(0)
        days.append({})#push dictionary
        customers = []
        while(entry != "CLOSE"):#line in current entry
            if (entry != "OPEN"):
                line = entry.split(" ")
                keyword = line[0]
                name = line[1]
                minutes = int(line[2])
                if (keyword == "ENTER"):
                    customers.append(name)
                    days[dayIndex][name] = minutes
                elif (keyword == "EXIT"):
                    entryMinute = days[dayIndex][name]
                    time = minutes - entryMinute
                    days[dayIndex][name] = time*0.1#calculate amount owed
                customers = sorted(customers)#sort alphabetically
                customersPerDay.append(customers)
                dayIndex+=1#increment day
    else:#done with input
        break
"""
for dayIndex in range(len(customersPerDay)):
    print("Day "+str(dayIndex+1))
    dayCustomers = customersPerDay[dayIndex]
    for customerIndex in range(len(dayCustomers)):
        customer = dayCustomers[customerIndex]
        print(customer + " $"+str(days[dayIndex][customer]))
    print("\n")
"""
