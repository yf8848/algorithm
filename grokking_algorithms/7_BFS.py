#!/bin/env python3

from collections import deque

def can_be_fini(node):
    if "finish" == node:
        return True
    return False

def fill_parent(graph, node, parent):
    for n in graph[node]:
        parent[n] = node

def show_road(parent):
    road = "-->finish"
    node = parent["finish"]
    while node is not None:
        road = "-->" + node + road
        node = parent[node]

    print("shortest Road:%s" % road)

def BFS(graph):
    search_queue = deque()
    search_queue += graph["start"]

    parent = {}                                       # 记录路径
    parent["start"] = None
    fill_parent(graph,"start", parent)

    while search_queue:                             # while queue not empty
        node = search_queue.popleft()               
        if can_be_fini(node):
            show_road(parent)
            return True
        else:
            search_queue += graph[node]
            fill_parent(graph, node, parent)

def creat_graph():
    graph={}
    graph = {}
    graph["start"] = ["alice", "bob", "claire"]
    graph["bob"] = ["anuj", "peggy"]
    graph["alice"] = ["peggy"]
    graph["claire"] = ["finish", "jonny"]
    graph["anuj"] = []
    graph["peggy"] = []
    graph["finish"] = []
    graph["jonny"] = []

    print("graph : %s" % graph)
    return graph

if __name__ == "__main__":
    BFS(creat_graph())