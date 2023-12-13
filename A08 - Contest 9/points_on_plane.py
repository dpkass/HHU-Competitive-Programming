# Created by dpkass

from decimal import getcontext, Decimal
from math import ceil

getcontext().prec = 100

def _str(): return input()
def _int(): return int(_str())
def _strs(): return _str().split(' ')
def _ints(): return list(map(int, _strs()))

t = _int()
for _ in range(t):
    v = Decimal(_int())
    ans = ceil(v ** Decimal(.5)) - 1

    if (ans + 1) ** 2 < v: ans += 1
    print(int(ans))
