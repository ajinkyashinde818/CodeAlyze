import sys
from math import ceil, floor
from collections import deque, Counter, defaultdict
from fractions import gcd
input = lambda: sys.stdin.readline().rstrip()

def eprint(s):
    sys.stderr.write('DEBUG: {}'.format(s))
    return

def main():
    s = input()
    q = int(input())
    ans = deque()
    swap = False
    for i in range(len(s)):
        ans.append(s[i])

    for i in range(q):
        #print(ans, swap)
        inp = input()
        if len(inp) == 1:
            hoge = int(inp)
            if swap:
                swap = False
            else:
                swap = True
        else:
            # print(tuple(inp))
            fi, ci = tuple(inp)[2], tuple(inp)[4]
                       
            if int(fi) == 1:
                if not swap:
                    ans.appendleft(ci)
                else:
                    ans.append(ci)
            if int(fi) == 2:
                if not swap:
                    ans.append(ci)
                else:
                    ans.appendleft(ci)
    s_ans = str()
    ans = list(ans)
    if swap:
        for i in range(len(ans)-1,-1, -1):
            s_ans += ans[i]
    else:
        for i in range(len(ans)):
            s_ans += ans[i]
    
    print(s_ans)
                
    return

if __name__ == '__main__':
    main()
