D, G = [int(_) for _ in input().split()]

p = [[i*100] + [int(_) for _ in input().split()] for i in range(1, D+1)]
p.sort(reverse=True)

def dfs(pos, total, maxpos, count, ans):
    if total >= G:
        if count < ans:
            return count
    if pos >= D:
        if maxpos < D:
            for i in range(1, p[maxpos][1]+1):
                if total + i * p[maxpos][0] >= G:
                    if count + i < ans:
                        return count + i
        return ans

    ans1 = dfs(pos+1, total, maxpos, count, ans)
    ans2 = dfs(pos+1, total+p[pos][0]*p[pos][1]+p[pos][2],
            maxpos+1 if pos==maxpos else maxpos, count+p[pos][1], ans)

    return min(ans, ans1, ans2)

print(dfs(0,0,0,0,10000))
