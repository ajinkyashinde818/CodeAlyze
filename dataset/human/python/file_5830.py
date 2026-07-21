def main():
    N = int(input())
    A = [int(x) for x in input().split()]
    B = [int(x) for x in input().split()]
    C = [int(x) for x in input().split()]
    ans = sum(B)
    k = -1
    for i in A:
        if i == k + 1:
            ans += C[k-1]
        k = i
    print(ans)


if __name__ == "__main__":
    main()
