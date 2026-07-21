def resolve():
    K,N = map(int,input().split())
    A = list(map(int,input().split()))

    A.sort()

    x = A[-1] - A[0]
    x = min(x, K - A[1]+A[0])

    for i in range(1,N-1):
        x = min(x, K - A[i+1]+A[i])

    print(x)


    



if __name__ == "__main__":
    resolve()
