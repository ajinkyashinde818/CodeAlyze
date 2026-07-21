K,N = map(int,input().split())
A = list(map(int,input().split()))
def solver(K,N,A):
    distance = [A[0] + (K - A[N-1])]
    for i in range(1,N):
        distance.append(abs(A[i]-A[i-1]))
    max_value = max(distance)
    return K - max_value
print(solver(K,N,A))
