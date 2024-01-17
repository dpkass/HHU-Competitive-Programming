# Created by dpkass
# ID - NAME
from collections import defaultdict as ddict

def _str(): return input()
def _int(): return int(_str())
def _strs(): return _str().split(' ')
def _ints(): return tuple(map(int, _strs()))

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n + 1))
        self.size = [0 for _ in range(n + 1)]

    def find(self, v):
        while v != self.parent[v]:
            self.parent[v] = self.parent[self.parent[v]]
            v = self.parent[v]
        return v

    def union(self, u, v):
        ru = self.find(u)
        rv = self.find(v)
        if ru == rv: return False

        if self.size[ru] > self.size[rv]:
            self.parent[rv] = ru
            self.size[ru] += 1
        else:
            self.parent[ru] = rv
            self.size[rv] += 1

        return True

def dfs(edges, vis, v):
    if vis[v]: return
    vis[v] = True
    for u, w in edges[v]:
        dfs(edges, vis, u)

def kruskal(edges):
    uf = UnionFind(n)
    or_weight = 0
    count = 1

    es = [(w, u, v) for u, l in edges.items() for v, w in l]
    es.sort()

    for w, u, v in es:
        if uf.union(u, v):
            or_weight |= w
            count += 1
            if count == n: return or_weight

    return None

def msb(w: int, *_): return w.bit_length() - 1

t = _int()
for _ in range(t):
    _str()
    n, m = _ints()

    edges = ddict(lambda: list())
    max_w = 0
    for _ in range(m):
        u, v, w = _ints()
        max_w = max(max_w, w)
        edges[u].append((v, w))
        edges[v].append((u, w))

    for i in range(msb(max_w), -1, -1):
        bit = 1 << i

        edges_without_bit = ddict(lambda: list())
        for v, l in edges.items():
            for u, w in l:
                if not w & bit:
                    edges_without_bit[v].append((u,w))
        vis = [0 for _ in range(n + 1)]
        dfs(edges_without_bit, vis, 1)
        if sum(vis) == n:
            edges = edges_without_bit

    print(kruskal(edges))
