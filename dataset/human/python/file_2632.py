d, g = map(int, input().split())
p = [0] * d
c = [0] * d
for i in range(d):
    p[i], c[i] = map(int, input().split())
ans = []
def greedy(count,comp,diff):
    ret = -1
    for i in range(d-1,-1,-1):
        if not(i in comp):
            if (p[i]-1)*(i+1)*100 >= diff:
                ret = count + diff//((i+1)*100) + (diff % ((i+1)*100) != 0)
                break
    return ret

def search(i,score,count,comp):
    if i == d:
        if score >= g:
            ans.append(count)
            return
        res = greedy(count,comp,g - score)
        if res != -1:
            ans.append(res)
    else:
        search(i+1,score,count,comp)
        comp.append(i)
        search(i+1,score+p[i]*(i+1)*100+c[i],count+p[i],comp)
search(0,0,0,[])
print(min(ans))
