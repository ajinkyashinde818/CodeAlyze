import sys

sys.setrecursionlimit(10**6)

def f(n):
    if n < 2:
        return 1
    else:
        return n * f(n-2)

def g(n):
    m = int(str(n)[:-1])
    ans = 0
    for i in range(30):
        tmp = m//pow(5, i)
        if tmp == 0:
            break
        ans += tmp
    return ans


def main():
    N = int(input())
    if N < 10:
        print(0)
        return
    if N%2==1:
        print(0)
        return
    print(g(N))


if __name__ == "__main__":
    main()
