import sys
input=sys.stdin.readline

def main():
    _ = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))
    ans = 0
    tmp = -1
    for a in A:
        ans += B[a-1]
        if tmp + 1 == a:
            ans += C[a-2]
        tmp = a

    print(ans)
if __name__ == '__main__':
    main()
