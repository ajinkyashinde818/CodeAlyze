from sys import stdin
from collections import OrderedDict
import math


if __name__ == "__main__":
    _in = [_.rstrip() for _ in stdin.readlines()]
    D,G = list(map(int,_in[0].split(' ')))  # type:list(int)
    p_c_arr = []
    for i in range(D):
        _ = list(map(int,_in[i+1].split(' ')))  # type:list(int)
        p_c_arr.append(_)
    # vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
    cnt = float('inf')
    for bit in range(1<<D):
        score = 0
        prob = 0
        cache = OrderedDict()
        for i in range(D-1,-1,-1):
            if bit&(1<<i):
                score += 100*(i+1)*p_c_arr[i][0]+p_c_arr[i][1]
                prob += p_c_arr[i][0]
            else:
                cache[i+1] = p_c_arr[i]
        else:
            if score < G:
                for k,v in cache.items():
                    if G-score <= 100*k*(v[0]-1):
                        prob += math.ceil((G-score)/(100*k))
                        break
                    elif G-score <= 100*k*v[0]+v[1]:
                        prob += v[0]
                        break
                    else:
                        score += 100*k*v[0]+v[1]
                        prob += v[0]
        cnt = min(cnt,prob)
    ## ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    print(cnt)
