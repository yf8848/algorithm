#!/bin/env python3 

def greedy(stations, states_needed):
    fini_states = []
    while states_needed:
        state_covered = set()
        best_state = None
        for state,station in stations.items():
            cover = station & states_needed         # 未覆州台与当前电台覆盖州的交集
            if len(cover) > len(state_covered):
                state_covered   = cover
                best_state      = state
        states_needed -= state_covered
        fini_states.append(best_state)
    
    print("greedy result: %s." % fini_states)


def creat_stations():
    stations = {}
    stations["kone"] = set(["id", "nv", "ut"])
    stations["ktwo"] = set(["wa", "id", "mt"])
    stations["kthree"] = set(["or", "nv", "ca"])
    stations["kfour"] = set(["nv", "ut"])
    stations["kfive"] = set(["ca", "az"])
    return stations

if __name__ == "__main__":
    states_needed = set(["mt", "wa", "or", "id", "nv", "ut","ca", "az"])
    station = creat_stations()
    print(station, states_needed)
    greedy(station, states_needed)