# Created by dpkass
# ID - NAME


def _str(): return input()
def _int(): return int(_str())
def _strs(): return _str().split(' ')
def _ints(): return list(map(int, _strs()))

def find(x):
    while x != parent[x]:
        parent[x] = parent[parent[x]]
        x = parent[x]
    return x

def union(node1, node2):
    root1 = find(node1)
    root2 = find(node2)
    if root1 == root2:
        return False

    if size[root1] > size[root2]:
        parent[root2] = root1
        size[root1] += 1
    else:
        parent[root1] = root2
        size[root2] += 1

        return True

def partial_find(x, y):
    max_x = 0
    max_y = 0
    while parent[x] != y and parent[y] != x:
        max_x = max(max_x, ws[(x, parent[x])])
        max_y = max(max_y, ws[(y, parent[y])])
        x = parent[x]
        y = parent[y]
    if parent[x] == y: return max_x
    else: return max_y

def mst(e):
    e.sort()
    edges = set()
    edge_weight = 0

    for w, u, v in e:
        if union(u, v):
            edges.add((u, v))
            edges.add((v, u))
            edge_weight += w
    return edge_weight, edges

n, m = _ints()

weight = [0 for x in range(n + 1)]
parent = [x for x in range(n + 1)]
size = [1 for _ in range(n + 1)]

es = [_ints()[::-1] for _ in range(m)]
ws = {tuple(x[1:3]): x[0] for x in es}
ws.update({tuple(x[1:3:-1]): x[0] for x in es})

ew, min_es = mst(es)

for _, u, v in es:
    if (u, v) in min_es: print(ew)
    else: print(ew - partial_find(u, v))
