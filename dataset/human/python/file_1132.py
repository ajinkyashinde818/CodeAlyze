def main():
    from collections import Counter
    N = int(input())
    A = list(map(int,input().split()))
    B = list(map(int,input().split()))
    a_count = Counter(A)
    b_count = Counter(B)
    for k,v in (a_count + b_count).items():
        if N < v:
            print('No')
            return
    print('Yes')
    C = [0]*(N+1)
    idx = 0
    for a in A:
        while idx < a:
            idx += 1
            C[idx] = C[idx-1]
        C[idx] += 1
    while idx < N:
        idx += 1
        C[idx] = C[idx-1]

    D = [0]*(N+1)
    idx = 0
    for b in B:
        while idx < b:
            idx += 1
            D[idx] = D[idx-1]
        D[idx] += 1
    while idx < N:
        idx += 1
        D[idx] = D[idx-1]
    
    x = 0
    for i in range(1,N+1):
        x = max(x, C[i] - D[i-1])
        # print(x)
    print(*(B[N-x:]+B[:N-x]))
    # print(C)
    # print(D)

main()
