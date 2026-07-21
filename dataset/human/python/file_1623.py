import sys
IS = lambda: sys.stdin.readline().rstrip()
II = lambda: int(IS())
MII = lambda: list(map(int, IS().split()))
MIIZ = lambda: list(map(lambda x: x-1, MII()))

def main():
    n, m = MII()
    aa = [IS() for _ in range(n)]
    bb = [IS() for _ in range(m)]
    for i in range(n-m+1):
        for j in range(n-m+1):
            for k in range(m):
                if aa[i+k][j:j+m] != bb[k][:]: break
            else: print('Yes'); exit()
    print('No')

if __name__ == '__main__':
    main()
