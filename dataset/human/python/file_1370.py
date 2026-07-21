def solve():
    N = int(input())
    A = list(map(int, input().split()))

    y = sum(A)
    x = 0
    mn = float('inf')
    for i in range(N-1):
        x += A[i]
        y -= A[i]
        mn = min(mn, abs(x-y))
    
    print(mn)

if __name__ == '__main__':
    solve()
