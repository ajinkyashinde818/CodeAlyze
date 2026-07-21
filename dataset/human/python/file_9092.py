S = input()

ops = ('dream', 'dreamer', 'erase', 'eraser')

import sys
sys.setrecursionlimit(200000)

memo = [None] * (len(S) + 1)

def dp(pos):
    if pos > len(S): return 0
    elif pos == len(S): return 1
    elif memo[pos] != None: return memo[pos]
    #
    ret = 0
    for op in ops:
        # print("#", pos, S[pos : pos + len(op)], op)
        if S[pos : pos + len(op)] == op:
            ret = max(ret, dp(pos + len(op)))
    #
    memo[pos] = ret
    return ret

if dp(0) == 1:
    print('YES')
else:
    print('NO')
