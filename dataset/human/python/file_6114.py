def main():
    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))
    ans = sum(B)
    prev = -1
    for a in A:
        if a == prev + 1:
            ans += C[a - 2]
        prev = a
    print(ans)


if __name__ == '__main__':
    main()
