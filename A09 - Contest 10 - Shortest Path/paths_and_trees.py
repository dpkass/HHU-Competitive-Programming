# Created by dpkass
import queue

def _str(): return input()
def _int(): return int(_str())
def _strs(): return _str().split(' ')
def _ints(): return list(map(int, _strs()))

n, m = _ints()
n += 1
e = [{} for _ in range(n)]

for i in range(m):
    a, b, w = _ints()
    e[a][b] = e[b][a] = (w, i + 1)

start = _int()

done = [False] * n
q = queue.PriorityQueue()
q.put((0, start, 0, None))

ws = 0
e1 = []

while not q.empty():
    cd, cv, cw, cei = q.get()
    if done[cv]: continue
    done[cv] = True

    ws += cw
    e1.append(cei)

    for nbr, (w, i) in e[cv].items():
        if done[nbr]: continue
        q.put((cd + w, nbr, w, i))

print(ws)
print(*e1[1:])
