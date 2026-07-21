def main():
    N = int(input())
    A = [int(a) for a in input().split()]
    S = [0 for i in range(N+1)]
    for i in range(1, N+1):
        S[i] = S[i-1] + A[i-1]

    mi = 10**10
    for i in range(1, N):
        S1 = S[i] - S[0]
        S2 = S[N] - S[i]
        d = abs(S1-S2)
        
        if d < mi:
            mi = d
            
    print(mi)
        
if __name__ == "__main__":
    main()
