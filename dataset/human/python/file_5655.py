def main():
    from sys import setrecursionlimit, stdin
    from os import environ
    from collections import defaultdict, deque, Counter
    from math import ceil, floor
    from itertools import accumulate, combinations, combinations_with_replacement
    setrecursionlimit(10**6)
    dbg = (lambda *something: print(*something)) if 'TERM_PROGRAM' in environ else lambda *x: 0
    input = lambda: stdin.readline().rstrip()
    LMIIS = lambda: list(map(int,input().split()))
    II = lambda: int(input())
    P = 10**9+7
    INF = 10**9+10

    S = deque(input())
    N = len(S)
    ans = 0
    if len(S) == 1:
        print(0)
        return
    left = S.popleft()
    right = S.pop()
    while True:
        if left == right:
            if len(S) >= 2:
                left = S.popleft()
                right = S.pop()
                continue
            else:
                break
            
        if left != 'x' and right!='x':
            print(-1)
            return

        ans += 1
        if left == 'x':
            if len(S)>0:
                left = S.popleft()
            else:
                break
        elif right == 'x':
            if len(S)>0:
                right = S.pop()
            else:
                break

    print(ans)



            

        

main()
