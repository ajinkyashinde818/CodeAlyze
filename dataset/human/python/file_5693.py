def solve():
    S = input()
    non_x = ''
    num_x = []
    cnt = 0
    for s in S:
        if s == 'x':
            cnt += 1
        else:
            non_x += s
            num_x.append(cnt)
            cnt = 0
    num_x.append(cnt)
    if non_x != non_x[::-1]:
        return -1
    N = len(num_x)
    ans = 0
    for i in range(N):
        ans += abs(num_x[i]-num_x[-i-1])
    return ans//2
print(solve())
