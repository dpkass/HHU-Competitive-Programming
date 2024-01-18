# Created by dpkass

from bisect import bisect_left as binary_search
from math import comb as binom

def _str(): return input()
def _int(): return int(_str())
def _strs(): return _str().split(' ')
def _ints(): return list(map(int, _strs()))

class e18_list:
    def __init__(self, k): self.k = k

    def __len__(self): return int(1e18 + 1)

    def __getitem__(self, n): return countKbitsbetweenLR(n, 2 * n, self.k)

def msb(w: int, *_): return w.bit_length() - 1

def countKbitsbetweenLR(l, r, k): return countK1toN(r, k) - countK1toN(l, k)
def countK1toN(n, k):
    _msb = msb(n)
    res = bin(n).count('1') == k
    for i in range(_msb, -1, -1):
        if not 1 << i & n: continue
        res += binom(i, k)
        k -= 1
        if k == 0: break
    return res

m, k = _ints()
print(max(1, binary_search(e18_list(k), m)))
