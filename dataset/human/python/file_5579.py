import sys
input = sys.stdin.readline
from operator import itemgetter
sys.setrecursionlimit(10000000)

def main():
    s = input().strip()
    n = len(s)
    ans = 0
    i = 0
    j = n-1
    while i < j:
        if s[i] != s[j]:
            if s[i] == 'x':
                i += 1
                ans += 1
            elif s[j] == 'x':
                j -= 1
                ans += 1
            else:
                print(-1)
                return
        else:
            i += 1
            j -= 1
    print(ans)

if __name__ == '__main__':
    main()
