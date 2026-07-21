def main():
    K, N = [int(_) for _ in input().split()]
    A = list(map(int, input().split()))
    mx = 0

    for i in range(N-1):
        dis = A[i+1] - A[i]
        if dis > mx:
            mx = dis
    se = A[N-1] - A[0]
    
    if K-se > mx:
        mx = K - se
    print(K - mx)
main()
