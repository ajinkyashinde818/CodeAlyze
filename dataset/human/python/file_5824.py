def main():
    b = int(input())
    l_A = [int(i) for i in input().split()]
    l_B = [int(i) for i in input().split()]
    l_C = [int(i) for i in input().split()]

    last = -100
    ans = 0
    for A in l_A:
        ans += l_B[A-1]
        if A - last - 1 == 1:
            ans += l_C[A - 2]
        last = A-1
    print(ans)


if __name__ == "__main__":
    main()
