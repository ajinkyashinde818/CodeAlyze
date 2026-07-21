n = int(input())

def pFact(n):
    l=[]
    if(n==1):
        return [1]
    while(n%2==0):
        l.append(2)
        n//=2
    
    f=3
    while(f*f <= n):
        if(n%f==0):
            l.append(f)
            n//=f
        else:
            f += 2
    
    if(n!=1):
        l.append(n)
    return l

l = pFact(n)
dic = {}
div_l = []

for x in l:
    if(dic.get(x) is None):
        dic[x] = 1
    else:
        dic[x] += 1
cnt = 0
for x,y in dic.items():
    if(x==1):
        continue
    e = 1
    while((y-e)>=0):
        y -= e
        e += 1
        cnt += 1
print(cnt)
