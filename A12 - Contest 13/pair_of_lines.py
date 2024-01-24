# Created by dpkass


def _str(): return input()
def _int(): return int(_str())
def _strs(): return _str().split(' ')
def _ints(): return tuple(map(int, _strs()))

def on_line(a, b, c): return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0]) == 0

def _try(a, b):
    nps = [p for p in ps if not on_line(a, b, p)]
    return len(nps) < 2 or all(on_line(nps[0], nps[1], p) for p in nps)

n = _int()
ps = [_ints() for _ in range(n)]
print("YES" if n < 5 or _try(ps[0], ps[1]) or _try(ps[0], ps[2]) or _try(ps[1], ps[2]) else "NO")
