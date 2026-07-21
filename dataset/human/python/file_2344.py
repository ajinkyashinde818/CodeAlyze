d, g = map(int,input().split())
data = [list(map(int,input().split())) for _ in range(d)]

def dfs(d, rest): # difficulty, rest score
    if d <= 0: return 10**9
    num, bonus = data[d-1] # num of problems, bonus
    # now, use or don't use difficulty d?
    use = min(rest//(d*100), num) # num when use
    score = use * d * 100 # score when use
    if use == num: score += bonus # ?perfect
    if rest - score > 0: # ?rest
        use += dfs(d-1, rest - score) # rest of score -> recursion
    not_use = dfs(d-1, rest) # num when don't use -> recursion
    return min(use, not_use)

print(dfs(d, g))
