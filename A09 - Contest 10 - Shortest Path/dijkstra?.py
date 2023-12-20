# Created by dpkass
import queue

def _str(): return input()
def _int(): return int(_str())
def _strs(): return _str().split(' ')
def _ints(): return list(map(int, _strs()))


n, m = _ints()
n += 1
edges = [{} for _ in range(n)]

for _ in range(m):
    a, b, w = _ints()
    edges[a][b] = edges[b][a] = w

d = [float('inf')] * n
d[1] = 0
p = [None] * n
q = queue.PriorityQueue()
q.put((0, 1))

while not q.empty():
    cd, cv = q.get()
    if cv == n - 1: break
    if cd > d[cv]: continue

    for nbr, w in edges[cv].items():
        dist = cd + w

        if dist < d[nbr]:
            d[nbr] = dist
            p[nbr] = cv
            q.put((dist, nbr))

curr = n - 1
ans = [n - 1]
while curr != 1:
    if curr is None:
        print(-1)
        exit(0)
    curr = p[curr]
    ans.append(curr)
print(*ans[::-1])
