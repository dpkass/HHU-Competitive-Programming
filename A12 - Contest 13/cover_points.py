# Created by dpkass
# ID - NAME


def _str(): return input()
def _int(): return int(_str())
def _strs(): return _str().split(' ')
def _ints(): return list(map(int, _strs()))


n = _int()
ans = 0
for _ in range(n): ans = max(sum(_ints()), ans)
print(ans)
