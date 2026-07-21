def main():
    n, k, s = list(map(int, input().split()))
    ans = [0] * n
    for i in range(k):
        ans[i] = s
    if s == 10 ** 9:
        for i in range(k, n):
            ans[i] = 1
        print(" ".join(str(x) for x in ans))
    elif s > 1:
        stack = 0
        for i in range(k, n):
            if stack + 1 == s:
                stack = 0
                ans[i] = int(10 ** 9)
            else:
                stack += 1
                ans[i] = 1
        print(" ".join(str(x) for x in ans))
    else:
        for i in range(k, n):
            ans[i] = 2
        print(" ".join(str(x) for x in ans))
    return
if __name__ == "__main__":
    main()
