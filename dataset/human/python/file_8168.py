def ri(): return int(input())
def rli(): return list(map(int, input().split()))
def rls(): return list(input())
def pli(a): return "".join(list(map(str, a)))

k, s = rli()
ans = 0
for x in range(k+1):
    for y in range(k+1):
        z = -x-y+s
        if(0 <= z and z <= k):
            ans += 1
print(ans)
