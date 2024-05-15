# Created by dpkass
from collections import deque

def _str(): return input()
def _int(): return int(_str())
def _strs(): return _str().split(' ')
def _ints(): return list(map(int, _strs()))

def solve(sa, n):
    c = n
    ans = [0] * n
    pos, neg = 0, 0

    for _ in range(n):
        (lv, li), (rv, ri) = sa[0], sa[-1]

        if lv == pos:
            ans[li] = -c
            sa.popleft()
            neg += 1
        elif rv + neg == n:
            ans[ri] = c
            sa.pop()
            pos += 1
        else: return False
        c -= 1
    return ans

t = _int()
for _ in range(t):
    n = _int()
    a = _ints()
    sa = deque(sorted([(x, i) for x, i in zip(a, range(n))]))

    ans = solve(sa, n)
    if ans:
        print('YES')
        print(*ans)
    else:
        print('NO')
