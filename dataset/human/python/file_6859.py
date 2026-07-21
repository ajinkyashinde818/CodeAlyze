from sys import stdin
from collections import deque

if __name__ == "__main__":
    _in = [_.rstrip() for _ in stdin.readlines()]
    S =     _in[0]   # type:str
    Q =     _in[1]   # type:str
    Q_arr = []
    for __in in _in[2:]:
        _ = __in.split(' ')
        if len(_) == 1:
            Q_arr.append([int(_[0])])
        else:
            Q_arr.append([int(_[0]),int(_[1]),_[2]])
    # vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
    S_arr = deque([s for s in S])
    reverse = False
    for _Q in Q_arr:
        if _Q[0] == 1:
            reverse = not reverse
        elif (_Q[1] == 1 and (not reverse)) or (_Q[1] == 2 and reverse):
            S_arr.appendleft(_Q[2])
        else:
            S_arr.append(_Q[2])
    if reverse:
        S_arr.reverse()
    S_arr = list(S_arr)
    S = ''.join(S_arr)
    # ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    print(S)
