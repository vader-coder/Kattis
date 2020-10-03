#https://open.kattis.com/problems/onaveragetheyrepurple

def getPathEdges(graph, sink, count, node, countArr):
    if (node == sink):
        countArr.append(count)
    else:
        count += 1
        for i in graph[node]:
            getPathEdges(graph, sink, count, i, countArr)


graph = [[]]
info = input().split()
nodes = int(info[0])
edges = int(info[1])
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

#print(graph)
