def Main(K, N, A):
    dist = [0]*N
    for i in range(1, N):
        dist[i-1] = A[i] - A[i-1]
    dist[N-1] = K - A[N-1] + A[0]
    return sum(dist) - max(dist)

def main():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))
    print(Main(K, N, A))

if __name__ == '__main__':
    main()
