#inputs
#A2B2A1B2A2B1A2B2A1B2A1A1B1B1B2
#B2A1B2A2B1B2B2B2

scoreStr = input()
alice = 0
barbara = 0
tiedIndex = -1
tiedBy10 = 0
winner = ""
scoreStrLen = len(scoreStr)

for i in range(scoreStrLen):
    if (scoreStr[i] == 'A'):
        alice += int(scoreStr[i+1])
    elif (scoreStr[i] == 'B'):
        barbara += int(scoreStr[i+1])
    
    if (alice == 10 and barbara == 10):
        tiedBy10 = 1
        tiedIndex = i+1
        break
    elif ((not tiedBy10) and alice == 11 and alice > barbara):
        winner = "A"
        break
    elif ((not tiedBy10) and barbara == 11 and barbara > alice):
        winner = "B"
        break

if (tiedBy10):
    i = tiedIndex
    while (i<scoreStrLen):
        if (scoreStr[i] == 'A'):
            alice += int(scoreStr[i+1])
        elif (scoreStr[i] == 'B'):
            barbara += int(scoreStr[i+1])
        
        if (alice >= barbara+2):
            winner = "A"
            break
        elif(barbara >= alice+2):
            winner = "B"
            break
        
        i+=1
print(winner)
