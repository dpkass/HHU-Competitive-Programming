# Created by dpkass


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

def mst(e):
    e.sort()
    min_w = 0

    for w, u, v in e:
        if union(u, v):
            min_w += w
    return min_w

def line_graph(e):
    ne = {}
    for u in e:
        for v1, w1 in e[u]:
            for v2, w2 in e[v1]:
                a = (u, v1)
                b = (v1, v2)
                w = w1 + w2
                if a in ne: a.append((b,w))
                # else:
    return ne

t = _int()
for _ in range(t):
    n = _int()

    e = {i: [] for i in range(n + 1)}
    for _ in range(n - 1):
        u, v, w = _ints()
        e[u].append((v, w))
        e[v].append((u, w))

    e = line_graph(e)

    # parent = {x: x for x in set(e[:, 1]) + set(e)}
    # size = {x[1]: 1 for x in e} + {x[3]: 1 for x in e}

    print(mst(e))
