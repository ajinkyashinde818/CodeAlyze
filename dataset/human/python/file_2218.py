D, G = map(int,input().split())
problems = []
for _ in range(D):
    problems.append(list(map(int,input().split())))

def solve(n):
    N = n
    score = 0
    ans = 0
    for i in range(D):
        if N & 1:
            score += (i + 1) * 100 * problems[i][0] + problems[i][1]
            ans += problems[i][0]
        N >>= 1
    if score >= G:
        return ans
    i = D - 1
    while n & 2 ** i and i != -1:
        i -= 1
    if i == -1:
        return 10 ** 8
    cnt = 0
    while score + (i + 1) * 100 * cnt < G:
        cnt += 1
    if cnt >= problems[i][0]:
        return 10 ** 8
    return ans + cnt

MIN = 10 ** 8
for i in range(2 ** D):
    MIN = min(MIN, solve(i))
print(MIN)
