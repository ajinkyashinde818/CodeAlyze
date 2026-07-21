def resolve():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))
    A.append(K + A[0])
    l = max([A[i+1] - A[i] for i in range(N)])
    return print(K - l)

if __name__ == "__main__":
    resolve()
