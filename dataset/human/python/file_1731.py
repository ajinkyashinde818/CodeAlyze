def main():
    N, M = map(int, input().split())
    A, B = ['']*N, ['']*M
    for i in range(N):
        A[i] = input()
    for i in range(M):
        B[i] = input()
    ans = False
    len_a = len(A[0])
    len_b = len(B[0])
    for i in range(N - M + 1):
        for j in range(len_a - len_b + 1):
            match = True
            for k in range(M):
                a = A[i + k]
                b = B[k]
                if a[j:j+len_b] != b:
                    match = False
            if match:
                ans = True
                break
        if ans:
            break
    print('Yes' if ans else 'No')

if __name__ == '__main__':
    main()
