def main():
    N, K, S = list(map(int, input().split()))

    salt = -1 if S >= 10**9 else 1
    if K == 0:
        arr = [S+salt] *N
    else:
        arr = [] 
        for i in range(0, K):
            arr += [S]
        while len(arr) < N:
                arr += [S+salt]

    print(' '.join(map(str,arr)))

if __name__ == "__main__":
    main()
