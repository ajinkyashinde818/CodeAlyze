def main():
    K,N = map(int,input().split())
    A = list(map(int,input().split()))
    Aa = []
    for i in range(1,N):
        Aa.append(A[i]-A[i-1])
    Aa.append(K-A[N-1]+A[0])
    print(sum(Aa)-max(Aa))

if __name__ == "__main__":
    main()
