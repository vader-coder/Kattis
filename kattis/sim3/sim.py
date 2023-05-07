from collections import deque
import timeit

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.previous = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0
    def append(self, c):
        if self.size > 0:
            self.tail.next = Node(c)
            tail = self.tail
            self.tail = self.tail.next
            self.tail.previous = tail
        else:
            self.tail = Node(c)
            self.head = self.tail
        self.size += 1
    def pop(self):
        if self.size > 0:
            self.tail = self.tail.previous
            self.tail.next = None
            self.size -= 1
    def join(self, list2):
        self.append(list2.head)
        self.size += (list2.size-1)
    def print(self):
        current = self.head
        output = ""
        while (current != None):
            output += current.value
            current = current.next
        print(output)     


def parse(string):
    front = LinkedList()
    main = LinkedList()
    current = main
    for char in string:
        if char == '<':
            if current.size > 0:
                current.pop()
        elif char == ']':
            if front.size > 0:
                front.join(main)
                main = front
                front = LinkedList()
            current = main
        elif char == '[':
            if front.size > 0:
                front.join(main)
                main = front
                front = LinkedList()
            current = front
        else:
            current.append(char)
    if front.size > 0:
        front.join(main)
        main = front
    return main

#this takes too long.
#would do c extension but must be one file. 
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
        mylist = parse(string)
        mylist.print()
        #for char in list:
            #print(char, end='')

main()
