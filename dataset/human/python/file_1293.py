def solve(N,a):
    suma = 0
    SUM = sum(a)
    MIN = 10**15
    for i in a[:(N-1)]:
        suma+=i
        MIN = min(MIN,abs(2*suma-SUM))
    return abs(MIN)

if __name__ == "__main__":
    N = int(input())
    a = list(map(int,input().split()))
    print(solve(N,a))
