import sys

n, m = list(map(int, input().split()))

a = []
for i in range(0, n):
    a.append(list(input()))

b = []
for i in range(0, m):
    b.append(list(input()))

def diff(x, y):
    r = []
    for i in range(y, y+m):
        r.append(a[i][x:(len(b[0]) + x)])
    return r

if __name__ == '__main__':
    for i in range(0, (n - m)+1):
        for j in range(0, (n - m)+1):
            if(diff(i, j) == b):
                print('Yes')
                sys.exit()
    print('No')
