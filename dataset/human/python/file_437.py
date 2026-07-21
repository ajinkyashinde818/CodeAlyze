def main():
    n = int(input())
    arr = list(map(int, input().split()))
    mi = 1000000000
    s = 0
    cnt = 0
    for i in range(n):
        if arr[i] < 0:
            cnt += 1
            s -= arr[i]
            mi = min(mi, -arr[i])
        else:
            s += arr[i]
            mi = min(mi, arr[i])
    if cnt & 1:
        print(s - 2 * mi)
    else:
        print(s)
    return 0

main()
