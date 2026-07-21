def main():
    k, n = map(int, input().split())
    As = list(map(int, input().split()))

    diffs = [0]*n
    for i in range(n):
        if i == n-1:
            diffs[i] = k+As[0] - As[i]
        else:
            diffs[i] = As[i+1] - As[i]
    diffs.remove(max(diffs))
    ans = sum(diffs)
    print(ans)


if __name__ == "__main__":
    main()
