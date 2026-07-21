if __name__ == "__main__":
    K,N = map(int,input().split())
    A = list(map(int,input().split()))
    distance_arr = []
    for i in range(N-1):
        distance_arr.append(A[i+1]-A[i])
    distance_arr.append(K - A[N-1] + A[0])
    print(K - max(distance_arr))
