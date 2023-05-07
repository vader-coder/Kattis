correct = input()
entered = input()

answer = "No"
correctLen = len(correct)
enteredLen = len(entered)
if (correct == entered):
    answer = "Yes"
elif (correctLen == (enteredLen+1)):
    if correct[correctLen-1].isdigit():
        answer = "Yes"
    elif correct[0].isdigit():
        answer = "Yes"
elif (correct == (entered.swapcase())):
    answer = "Yes"

print(answer)