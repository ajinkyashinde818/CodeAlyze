def solve(n, aaa):
    added_once = n * (n + 1) // 2
    total = sum(aaa)
    d, m = divmod(total, added_once)
    if m != 0:
        return False
    cnt = 0
    for a1, a2 in zip(aaa, aaa[1:] + aaa[:1]):
        k = d - (a2 - a1)
        kd, km = divmod(k, n)
        if kd < 0 or km != 0:
            return False
        cnt += kd
    assert cnt == d
    return True


n = int(input())
aaa = list(map(int, input().split()))
print('YES' if solve(n, aaa) else 'NO')
