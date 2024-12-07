import heapq

class Edge:
    def __init__(self, to, weight):
        self.to = to
        self.weight = weight

def prim(n, adj):
    visited = [False] * (n + 1)
    pq = []
    heapq.heappush(pq, (0, 1))
    tongTrongSo = 0
    e = 0

    while pq and e < n:
        w, u = heapq.heappop(pq)
        if visited[u]:
            continue
        visited[u] = True
        tongTrongSo += w
        e += 1
        for edge in adj[u]:
            if not visited[edge.to]:
                heapq.heappush(pq, (edge.weight, edge.to))
    
    if e < n:
        return -1
    
    return tongTrongSo


import sys
input = sys.stdin.read
data = input().splitlines()

n, m = map(int, data[0].split())
adj = [[] for _ in range(n + 1)]

for i in range(1, m + 1):
    u, v, c = map(int, data[i].split())
    adj[u].append(Edge(v, c))
    adj[v].append(Edge(u, c))


print(prim(n, adj))
