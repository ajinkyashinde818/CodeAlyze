n, k = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]

def find_min_cycle(a):
    memo = {1: 0}
    idx = 0
    cnt = 1

    while a[idx] not in memo:
        memo[a[idx]] = cnt
        cnt += 1
        idx = a[idx]-1

    return memo[a[idx]], cnt-memo[a[idx]], memo

offset, cycle_len, memo = find_min_cycle(a)
rmemo = {v: k for k, v in memo.items()}

if k <= offset:
    print(rmemo[k])
else:
    i = (k-offset)%cycle_len
    print(rmemo[offset+i])
