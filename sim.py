from collections import deque
import timeit

def parse(string):
    front = deque([])
    main = deque([])
    current = main
    for char in string:
        if char == '<':
            if len(current) > 0:
                current.pop()
        elif char == ']':
            if len(front) > 0:
                main = front+main
                front = deque([])
            current = main
        elif char == '[':
            if len(front) > 0:
                main = front+main
                front = deque([])
            current = front
        else:
            current.append(char)
    if len(front) > 0:
        main = front+main
    return main

#this takes too long.
def dequeToString(mydeque):
    str = ""
    for char in mydeque:
        str += char
    return str

def main():
    test_cases = int(input())
    #outputs = deque([])
    for test in range(test_cases):
        string = input()
        list = parse(string)
        for char in list:
            print(char, end='')

main()
