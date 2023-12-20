# Created by dpkass


def _str(): return input()
def _int(): return int(_str())
def _strs(): return _str().split(' ')
def _ints(): return list(map(int, _strs()))

def dfs(u, has_loop):
    has_loop = has_loop or res[u] == -1

    if not color[u]:
        color[u], res[u] = 1, -1 if has_loop else 1
        for nbr in g[u]: dfs(nbr, has_loop)
        color[u] = 2
    elif has_loop: res[u] = -1
    elif color[u] == 2: res[u] = 2
    elif color[u] == 1: res[u] = -1

t = _int()
for _ in range(t):
    _ = _str()
    n, m = _ints()
    n += 1
    g = [[] for _ in range(n)]
    res = [0 for _ in range(n)]

    for _ in range(m):
        a, b = _ints()
        if a == b: res[a] = -1; continue
        g[a].append(b)

    color = [0 for _ in range(n)]
    dfs(1, res[1] == -1)

    color = [0 for _ in range(n)]
    dfs(1, res[1] == -1)

    print(*res[1:])

