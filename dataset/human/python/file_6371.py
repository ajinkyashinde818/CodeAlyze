import sys
IS = lambda: sys.stdin.readline().rstrip()
II = lambda: int(IS())
MII = lambda: list(map(int, IS().split()))

def main():
    n = II()
    cnt = 0
    val = 10
    if n%2==1: print(cnt); exit(0)
    while True:
        if n < val: break
        cnt += n//val
        val *= 5
    print(cnt)

if __name__ == '__main__':
    main()
