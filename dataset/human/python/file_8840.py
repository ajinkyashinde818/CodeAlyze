N = [int(_) for _ in input().split()]
K, N = N[0], N[1]
A = [int(_) for _ in input().split()]

def solve(K, N, A):
    
    hoge = A[0]
    B = []
    for i in range(1, N):
        B.append(A[i] - hoge)
        hoge = A[i]
    
    B.append( K - A[N-1] + A[0])
    return sum(B) - max(B)

print(solve(K, N, A))
