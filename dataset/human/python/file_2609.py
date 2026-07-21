D, G = map(int, input().split())
plist, clist = [], []

for _ in range(D):
    p,c = map(int, input().split())
    plist.append(p)
    clist.append(c)

def dfs(i, s, not_used):
    if i==D:
        if len(not_used)==0:
            return True, 0
        u = max(not_used)
        for p in range(plist[u-1]):
            if s + p * (u*100) >= G:
                return True, p
        return False, 0
    
    check1, num1 = dfs(i+1, s+plist[i]*(i+1)*100+clist[i], not_used)
    check2, num2 = dfs(i+1, s, not_used+[i+1])

    if check1 and check2:
        if num1 + plist[i] <= num2:
            return True, num1 + plist[i]
        else:
            return True, num2
    
    if check1:
        return True, num1 + plist[i]
    
    if check2:
        return True, num2
    
    else:
        return False, 0
    

_, ans = dfs(0, 0, [])

print(ans)
