def is_include(mid, m, book):
    cnt = 1
    length = 0
    for sz in book:
        if sz > mid:
            return False
        if length + sz <= mid:
            length += sz
        else:
            cnt += 1
            length = sz
    return cnt <= m

while True:
    m, n = map(int, raw_input().split())
    if m == n == 0:
        break
    book = [input() for i in range(n)]
    l = 1
    r = 1500000
    ans = 10000000
    while l <= r:
        mid = (l + r) / 2
        if is_include(mid, m, book):
            r = mid - 1
            ans = min(ans, mid)
        else:
            l = mid + 1
    print ans
