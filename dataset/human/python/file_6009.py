def main():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))

    ans = 0
    tmp = -100
    for a in A:
        ans += B[a-1]
        if a - tmp == 1:
            ans += C[tmp-1]
        
        tmp = a

    print(ans)


main()
