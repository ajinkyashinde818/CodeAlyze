def solve():
    N = int(raw_input())
    arr = [int(_) for _ in raw_input().split()]
    neg_cnt = 0
    abs_sum = 0
    min_abs = 10**10
    for i in range(N):
        abs_sum += abs(arr[i])
        if abs(arr[i]) < min_abs:
            min_abs = abs(arr[i])
        if arr[i] < 0:
            neg_cnt += 1
    if neg_cnt % 2 == 0:
        ret = abs_sum
    else:
        ret = abs_sum - 2 * min_abs
    print str(ret)

if __name__ == '__main__':
    solve()
