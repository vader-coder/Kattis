adrian = ['A', 'B', 'C']
adrianStr = 'ABC'
brunoStr = 'BABC'
goranStr = 'CCAABB'

questions = int(input())
answers = input()
adrianCorrect = 0
brunoCorrect = 0
goranCorrect = 0

adrianStrLen = len(adrianStr)
brunoStrLen = len(brunoStr)
goranStrLen = len(goranStr)

adrianIndex = 0
brunoIndex = 0
goranIndex = 0
for i in range(len(answers)):
    if (answers[i] == adrianStr[adrianIndex]):
        adrianCorrect+=1
    if (answers[i] == brunoStr[brunoIndex]):
        brunoCorrect+=1
    if (answers[i] == goranStr[goranIndex]):
        goranCorrect+=1
    adrianIndex+=1
    brunoIndex+=1
    goranIndex+=1
    if (adrianIndex >= adrianStrLen):
        adrianIndex = 0
    if (brunoIndex >= brunoStrLen):
        brunoIndex = 0
    if (goranIndex >= goranStrLen):
        goranIndex = 0

maxCorrect = max(goranCorrect, adrianCorrect, brunoCorrect)
names = ""
if (adrianCorrect == maxCorrect):
    names += "Adrian"
if (brunoCorrect == maxCorrect):
    names += "\nBruno"
if (goranCorrect == maxCorrect):
    names += "\nGoran"
print(str(maxCorrect)+"\n"+names)