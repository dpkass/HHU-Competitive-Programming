# Created by dpkass
# ID - NAME


def _str(): return input()
def _int(): return int(_str())
def _strs(): return _str().split(' ')
def _ints(): return list(map(int, _strs()))

# (n+1)*n/2 0 -> 30
sm_gaus = [int(((n + 1) * n) / 2) for n in range(31)]

t = _int()
for _ in range(t):
    n, k = _ints()

    pos_sub_arr_sizes = []
    last_i = len(sm_gaus) - 1
    while k > 0:
        for i in range(last_i, -1, -1):
            val = sm_gaus[i]
            if val == 0: break
            if val <= k:
                pos_sub_arr_sizes.append(i)
                last_i = i
                k -= val
                break

    ans = []
    for sz in pos_sub_arr_sizes:
        ans += [1 for _ in range(sz)]
        ans.append(-1000)

    ans += [-1000] * 30

    print(*ans[:n])
