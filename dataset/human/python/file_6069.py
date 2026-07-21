def p_b():
    N = int(input())
    A = list(map(int, input().split()))
    A = [i - 1 for i in A]
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))

    ans = 0

    bf = -100
    for i in A:
        ans += B[i]
        if bf == i - 1:
            ans += C[i - 1]
        bf = i

    print(ans)


if __name__ == '__main__':
    p_b()
