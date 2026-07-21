import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    d, g = f()
    ps = [ f() for i in range(d)]

    ans = 1e9
    for all_solve in range(1<<d):
        score = 0
        max_unused = 0
        cnt_p = 0
        for j in range(d):
            if all_solve&(1<<j):
                score += ps[j][0] * 100 *(j+1) + ps[j][1]
                cnt_p += ps[j][0]
            else:
                max_unused = j
        if score>g:
            ans = min(ans, cnt_p)
            continue
        
        max_unused_score = 100*(max_unused+1)
        if (g - score+ max_unused_score -1 )//max_unused_score > ps[max_unused][0]:
            continue
        else:
            cnt_p += (g - score+ max_unused_score -1 )//max_unused_score
        
        ans = min(ans,cnt_p)
    
    print(ans)


solve()
