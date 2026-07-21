import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


d,g = list(map(int, input().split()))
pc = [None]*d
for i in range(d):
    pc[i] = tuple(map(int, input().split()))
pc = pc[::-1]
ans = float("inf")
for b in range(1<<d):
    nokori = g
    val = 0
    for i in range(d):
        if b>>i&1:
            nokori -= (pc[i][0]*100*(d-i) + pc[i][1])
            val += pc[i][0]
    
    if nokori>0:
        for j in range(d):
            if b>>j&1:
                continue
            if pc[j][0]*100*(j+1)>=nokori:
                tmp = nokori//(100*(d-j)) + int(nokori%(100*(d-j))>0)
                val += tmp
                nokori -= tmp*(100*(d-j))                    
            else:
                nokori -= (pc[j][0]*100*(d-j) + pc[j][1])
                val += pc[j][0]
            if nokori<=0:
                break
    ans = min(ans, val)
print(ans)
