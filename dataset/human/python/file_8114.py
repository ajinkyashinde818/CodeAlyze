def count(i, j, k):
    if i == j and j == k:
        return 1
    elif i == j or j == k or i == k:
        return 3
    else:
        return 6

def solve(K, S):
    ans = 0
    for i in range(K, -1, -1):
        for j in range(i, -1, -1):
            k = S - (i + j)
            if k >= 0 and k <= j:
                ans += count(i, j, S - (i + j))
    return ans

k, s = tuple(int(x) for x in input().split())
print(solve(k, s))
