#https://open.kattis.com/problems/onaveragetheyrepurple

import sys
sys.setrecursionlimit(10**6) 


def getPathEdges(graph, sink, count, node, countArr):
    if (node == sink):
        countArr.append(count)
    else:
        count += 1
        for i in graph[node]:
            getPathEdges(graph, sink, count, i, countArr)

def main(nodes, edges):
    graph = [[]]
    if edges == 0 or nodes <=1:
        print(0)
    else: 
        sink = 0
        for i in range(edges):
            edge = input().split()
            edge = [int(edge[0])-1, int(edge[1])-1]
            if (edge[1] > sink):
                sink = edge[1]
            last = len(graph)-1
            if edge[0] > last:#new node greater than last
                for i in range(edge[0]-last):
                    graph.append([])
            graph[edge[0]].append(edge[1])
        pathArr = []
        getPathEdges(graph, sink, 0, 0, pathArr)
        print(min(pathArr)-1)
        

graph = []
path = []
for i in range(10000):
    graph.append([i+1])
print(graph[len(graph)-1])
#print(graph)
#def getPathEdges(graph, sink, count, node, countArr):
getPathEdges(graph, 10000-1, 0, 0, path)
print(min(path)-1)
"""info = input().split()
nodes = int(info[0])
edges = int(info[1])
main(nodes, edges)
"""


#print(graph)
