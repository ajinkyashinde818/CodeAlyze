import sys

def pmatch(A, B, X, Y):
    for y, Bx in enumerate(B):
        for x, b in enumerate(Bx):
            if A[Y+y][X+x] != b:
                return False
    return True

def main():
    raw = sys.stdin.readlines()
    N, M = map(int, raw[0].split())
    A = [i.rstrip() for i in raw[1:N+1]]
    B = [i.rstrip() for i in raw[N+1:]]

    rg = range(N-M+1)

    for Y in rg:
        for X in rg:
            if pmatch(A, B, X, Y):
                return True

    return False

if main():
    print('Yes')
else:
    print('No')
