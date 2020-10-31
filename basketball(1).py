scoreStr = input()
alice = 0
barbara = 0
tiedBy10 = 0
winner = ""

for i in range(len(scoreStr)):
    if (scoreStr[i] == 'A'):
        alice += int(scoreStr[i+1])
    elif (scoreStr[i] == 'B'):
        barbara += int(scoreStr[i+1])
    
    if (alice == 10 and barbara == 10):
        tiedBy10 = 1
    elif (tiedBy10 and barbara >= alice + 2):
        winner = "B"
        break
    elif (tiedBy10 and alice >= barbara + 2):
        winner = "A"
        break
    elif (not tiedBy10 and alice == 11 and alice > barbara):
        winner = "A"
        break
    elif (not tiedBy10 and barbara == 11 and barbara > alice):
        winner = "B"
        break

print(winner)