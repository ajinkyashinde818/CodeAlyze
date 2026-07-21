def main():
    N = int(input())
    A = list(int(x) for x in input().split())
    B = list(int(x) for x in input().split())
    C = list(int(x) for x in input().split())
    ans = 0
    a1 = N

    for a in A:
        ans += B[a-1]
        if a - a1 == 1:
            ans += C[a1-1]
        a1 = a
    print(ans)

if __name__ == '__main__':
    main()
