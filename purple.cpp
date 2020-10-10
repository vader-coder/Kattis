#include <iostream>
#include <vector>
using namespace std;

int min(vector<int>* path) {
    int ret = path->at(0);
    int curr;
    for (int i=1; i<path->size(); i++) {
        curr = path->at(i);
        if (curr<ret) {
            ret = curr;
        }
    }
    return ret;
}
//getPathEdges(graph, sink, count, node, countArr):
void getPathEdges(vector<vector<int>>* graph, int sink, int count, int node, vector<int>* path) {
    if (node == sink) {
        path->push_back(count);
    }
    else {
        count++;
        int size = graph->at(node).size();
        for (int i=0; i<size; i++) {
            getPathEdges(graph, sink, count, i, path);
        }
    }
}

int main() {
    int nodes, edges;
    int head, tail, last;
    cin >> nodes;
    cin >> edges;
    vector<vector <int>> graph;
    if (edges==0 || nodes <=1) {
        cout << 0;
    }
    for (int i=0; i<edges; i++) {
        cin >> head;
        cin >> tail;
        head--;
        tail--;
        last = graph.size()-1;
        if (head > last) {
            for (int j=last+1; j<head; j++) {
                graph.push_back({});
            }
        } 
        graph[head].push_back(tail);
    }
    vector<int> path;
    getPathEdges(&graph, edges-1, 0, 0, &path);
    cout << min(&path);
    return 0;
}