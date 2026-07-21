def solve(bit_state, num, mod):
    for div in range(1, num + 1):
        if num % div == mod:
            cand[i].append(bit_state | (1 << div))
        if num % div > mod:
            solve(bit_state | (1 << div), num % div, mod)


n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

cand = [[] for i in range(n)]
for i in range(n):
    solve(0, a[i], b[i])
    if a[i] == b[i]:
        cand[i].append(0)

ans = 0
while True:
    max_ = 0
    for j in range(n):
        min_ = 10 ** 5
        for num in cand[j]:
            min_ = min(min_, num.bit_length() - 1)
        max_ = max(max_, min_)

    if max_ == 0:
        print(ans)
        break
    if max_ == 10 ** 5:
        print(-1)
        break
    ans += 2 ** max_
    
    tmp = [[] for i in range(n)]
    for j in range(n):
        for num in cand[j]:
            if num & (1 << max_):
                tmp[j].append(num - (1 << max_))
            else:
                tmp[j].append(num)
    cand = tmp[0:]
