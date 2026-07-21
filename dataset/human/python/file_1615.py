import sys,os
from collections import defaultdict, deque
from math import ceil, floor
if sys.version_info[1] >= 5:
    from math import gcd
else:
    from fractions import gcd
sys.setrecursionlimit(10**6)
write = sys.stdout.write
dbg = (lambda *something: print(*something)) if 'TERM_PROGRAM' in os.environ else lambda *x: 0
def main(given=sys.stdin.readline):
    input = lambda: given().rstrip()
    LMIIS = lambda: list(map(int,input().split()))
    II = lambda: int(input())
    MOD = 10**9+7

    N,M = LMIIS()
    A = [0]*N
    for i in range(N):
        A[i] = input()
    B = [0]*M
    for i in range(M):
        B[i] = input()
    if M > N:
        print('No')
        return
    for i in range(N-M+1):
        for j in range(N-M+1):
            found = True
            for k in range(M):
                for l in range(M):
                    if A[i+k][j+l] != B[k][l]:
                        found = False
                        break
                if not found:
                    break
            if found:
                print('Yes')
                return
    print('No')



if __name__ == '__main__':
    main()
