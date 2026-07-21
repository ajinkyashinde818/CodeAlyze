import sys
input = sys.stdin.readline
from operator import itemgetter
sys.setrecursionlimit(10000000)
INF = 10**30

def main():
    n, m = list(map(int, input().strip().split()))
    a = []
    b = []
    for i in range(n):
        a.append(input().strip())
    for i in range(m):
        b.append(input().strip())
    for i in range(n):
        if i + m > n:
            break
        for j in range(n):
            if j + m > n:
                break
            flag = False
            for p in range(m):
                for q in range(m):
                    if b[p][q] != a[i+p][j+q]:
                        flag = True
                        break 
            if flag:
                continue
            else:
                print('Yes')
                return
    print('No')

if __name__ == '__main__':
    main()
