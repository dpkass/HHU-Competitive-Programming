# Created by dpkass


def _str(): return input()
def _int(): return int(_str())
def _strs(): return _str().split(' ')
def _ints(): return list(map(int, _strs()))

def unique(l):
    element_count = {}
    for element in l:
        if element in element_count: element_count[element] += 1
        else: element_count[element] = 1
    return element_count

t = _int()
for _ in range(t):
    bulbs = list(_str())
    counts = unique(bulbs)

    if len(counts) == 1: print(-1)
    elif len(counts) == 3 or len(counts) == 4 or counts[bulbs[0]] == 2: print(4)
    else: print(6)
