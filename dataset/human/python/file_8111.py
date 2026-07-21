k,s = map(int, input().split())

def solve_2(num):
    if num > k:
        return k - (num-k) + 1
    else:
        return num + 1
ans = 0
first = 0
if s > 2*k:
    first = s -2*k
while first <= k:
    if s - first < 0:
        break
    ans += solve_2(s - first)
    first += 1

print(ans)
