def main():
    k, n = [int(e) for e in input().split()]
    A = [int(e) for e in input().split()]

    ma = A[0] + k - A[n - 1]
    mai = n - 1
    for i in range(n - 1):
        if A[i + 1] - A[i] > ma:
            ma = A[i + 1] - A[i]
            mai = i

    if mai == n - 1:
        ans = A[mai] - A[0]
    else:
        ans = A[mai] + k - A[mai + 1]

    print(ans)

if __name__ == "__main__":
    main()
