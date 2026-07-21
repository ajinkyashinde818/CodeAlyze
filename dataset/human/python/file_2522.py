d,g = map(int,input().split())
li = [list(map(int,input().split())) for _ in range(d)]

ans = 10**10

def score(count,sum,q,s):
    global ans
    if count == d+1:
        if s == 0:
            if g <= sum:
                ans = min(ans,sum)
        else:
            for i in range(li[s-1][0]+1):
                a = sum
                q2 = q
                if i == li[s-1][0]:
                    a += s*100*i + li[s-1][1]
                    q2 += i
                else:
                    a += s*100*i
                    q2 += i
                if g <= a:
                    ans = min(ans,q2)
    else:
        score(count+1,sum,q,count)
        score(count+1,sum+count*100*li[count-1][0]+li[count-1][1],q+li[count-1][0],s)

score(1,0,0,0)

print(ans)
