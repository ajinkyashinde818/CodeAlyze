import sys
input = sys.stdin.readline

def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    B = [1]
    a = 1
    check = [0] * len(A)
    while True:
        a = A[a - 1]
        if check[a - 1] == 1:
            x = B.index(a)
            roop = B[x:]
            print(roop[(K - x) % len(roop)])
            exit()
        B.append(a)
        check[a - 1] += 1
        if len(B) >= K + 1:
            print(B[K])
            exit()
if __name__ == '__main__':
    main()
