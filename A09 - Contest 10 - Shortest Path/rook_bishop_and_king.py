# Created by dpkass


def _str(): return input()
def _int(): return int(_str())
def _strs(): return _str().split(' ')
def _ints(): return list(map(int, _strs()))

r1, c1, r2, c2 = _ints()
rd, cd = abs(r1 - r2), abs(c1 - c2)

if r1 == r2 and c1 == c2:
    rook, bishop, king = [0] * 3
elif r1 == r2 or c1 == c2:
    rook = 1
    bishop = 2
    king = max(rd, cd)
else:
    rook = 2
    bishop = 1 if rd == cd else 2
    king = max(rd, cd)

if (r1 + r2) % 2 != (c1 + c2) % 2: bishop = 0

print(rook, bishop, king)
