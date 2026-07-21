import sys

def I(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def main():
    s = sorted(input())
    t = sorted(input(), reverse=True)
    n = len(s)
    m = len(t)
    if n < m:
        for i in range(n):
            if s[i] != t[i]:
                break
        else:
            print("Yes")
            sys.exit()
    for i in range(min(n, m)):
        if s[i] != t[i]:
            if s[i] < t[i]:
                print("Yes")
                sys.exit()
            break
    print("No")

if __name__ == '__main__':
    main()
