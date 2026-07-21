N = int(input())
A = list(map(int, input().split()))

def solve():
    ans = float("inf")
    araiguma = sum(A)
    snuke = 0
    for A_i in A[0:-1]:
        snuke += A_i
        araiguma -= A_i
        score = abs(araiguma - snuke)
        if score < ans:
            ans = score
    print(ans)


solve()
