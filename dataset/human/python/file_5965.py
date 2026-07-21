import sys
def main():
    input = sys.stdin.readline
    N = int(input())
    ABC = [list(map(int, input().split())) for _ in range(3)]
    A = ABC[0]
    B = ABC[1]
    C = ABC[2]

    ans = 0
    for i in range(N):
        a = A[i]
        ans += B[a-1]
        if i != N-1:
            if A[i+1] == A[i] + 1:
                ans += C[a-1]

    print(ans)

if __name__ == '__main__':
    main()
