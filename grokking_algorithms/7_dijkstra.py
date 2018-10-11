#!/bin/env python3

def find_lowest_cost_node(costs, processed):
    lowest_cost         = float("inf")
    lowest_cost_node    = None

    for node in costs:
        if costs[node] < lowest_cost and node not in processed:
            lowest_cost = costs[node]
            lowest_cost_node = node
    return lowest_cost_node
            

def dijkstra(graph):                                    # input graph
    processed = []                                      # processed node
    parent    = {}                                      # parent table

    costs = graph["start"]                              # costs table init. first is from start node
    costs["finish"] = float("inf")

    parent["finish"] = None
    for cnode in costs.keys():                           # init parent table from start node
        parent[cnode] = "start"

    node = find_lowest_cost_node(costs, processed)      # find the lowest cost node not processed.
    while node is not None:                             # while has unprocessed node
        cost = costs[node]
        neighbors = graph[node]                         # processed node's neighbors
        for n in neighbors:
            new_const = cost + neighbors[n]
            if costs[n] > new_const:                    # if find the lower cost to node's neighbor, update table cost,parent
                costs[n]    = new_const
                parent[n]   = node
        processed.append(node)                          # record processed node
        node = find_lowest_cost_node(costs, processed)

    
    road = "-->finish["+ str(costs["finish"])+"]"
    node  = parent["finish"]
    while node != "start":
        road = "-->"+node + "["+str(costs[node])+"]"+road
        node = parent[node]
    road = "start[0]" + road
    print(road)

def creatGraph():
    graph = {}
    graph["start"] = {}
    graph["start"]["a"] = 6
    graph["start"]["b"] = 2
    
    graph["a"] = {}
    graph["a"]["finish"] = 1
    
    graph["b"] = {}
    graph["b"]["a"] = 3
    graph["b"]["finish"] = 5
    
    graph["finish"] = {}
    print("graph:%s" % graph)
    return graph

if __name__ == "__main__":
    dijkstra(creatGraph())