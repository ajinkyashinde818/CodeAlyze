def main():
    N = int(input())
    A = [int(a) for a in input().split()]
    v = 0
    tot = sum(A)
    min_d = float('inf')
    for i in range(N-1):
        v += A[i]
        min_d = min(min_d, abs(tot - 2*v))

    return min_d

if __name__ == '__main__':
    print(main())
