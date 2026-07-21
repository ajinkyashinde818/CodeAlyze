def main():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))

    A.append(K+A[0])
    ans = K

    for i in range(0, N):
        tmp = K - (A[i+1] - A[i])
        if tmp < ans:
            ans = tmp
    print(ans)







    return 0


if __name__ == '__main__':
    main()
