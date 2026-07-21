import sys
input = sys.stdin.readline

def main():
    k, n = map(int, input().split())
    a = list(map(int, input().split()))
    a += [k + a[0]]

    maxi = 0
    ind = 0
    for i in range(n):
        if maxi < a[i+1] - a[i]:
            maxi = a[i+1] - a[i]
            ind = i

    for i in range(ind+1, n):
        yield a[i+1] - a[i]

    for i in range(0, ind):
        yield a[i+1] - a[i]


print(sum(main()))
