import sys
input = sys.stdin.readline
def 解():
    iN,iM = [int(_) for _ in input().split()]
    a1 = [0]*iN
    aN = [0]*iN
    for i in range(iM):
        a,b = [int(_) for _ in input().split()]
        if a == 1:
            a1[b] = 1
        if b == iN:
            aN[a] = 1
    for i in range(iN):
        if a1[i] and aN[i]:
            print("POSSIBLE")
            exit()
    print("IMPOSSIBLE")
解()
