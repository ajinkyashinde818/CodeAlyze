if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))
    A = [i-1 for i in A]
    ans = 0
    before = -10
    for a in A:
        ans += B[a]
        if a-1 == before:
            ans += C[a-1]
        before = a
    print(ans)
