K, N = map(int, input().split())
A = list(map(int, input().split()))
def circle_distances(A,K,N):
    ret = []
    for i in range(N):
        if i == N-1:
            d = K - abs(A[0] - A[i])
        else:
            d = A[i+1] - A[i]
        ret.append(d)
    return ret
distances = circle_distances(A,K,N)
print(K -max(distances))
