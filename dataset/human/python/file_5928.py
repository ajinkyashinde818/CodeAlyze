def main():
    N=int(input())
    A=list(map(int, input().split()))
    B=list(map(int, input().split()))
    C=list(map(int, input().split()))
    prev_a = -1
    ans = 0
    for a in A:
        ans += B[a-1]
        if prev_a + 1 == a:
            ans += C[prev_a-1]
        prev_a = a
    print(ans)

if __name__ == '__main__':
    main()
