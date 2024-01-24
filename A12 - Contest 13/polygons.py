# Created by dpkass


def _str(): return input()
def _int(): return int(_str())
def _strs(): return _str().split(' ')
def _ints(): return tuple(map(int, _strs()))

def is_left(a, b, c): return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0]) >= 0
def out_of_hull(p, hull): return any(is_left(a, b, p) for a, b in zip([hull[-1]] + hull[:-1], hull))
n = _int()
hull = [_ints() for _ in range(n)]
print("NO" if any(out_of_hull(_ints(), hull) for _ in range(_int())) else "YES")

# time limit exceeded
