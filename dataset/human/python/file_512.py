def main():
    n = int(input())
    A = list(map(int, input().split()))
    c = 0
    for i in range(n):
        if A[i] < 0:
            c += 1
            A[i] = -A[i]
    if c % 2 == 0:
        print(sum(A))
    else:
        print(sum(A) - 2 * min(A))

if __name__ == '__main__':
    main()
