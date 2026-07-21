D, G = map(int,input().split())
L = []
ans = []
def ceil(i):
    if int(i) == i:
        return int(i)
    else:
        return int(i)+1


for _ in range(D):
    l = list(map(int,input().split())) +[0]
    L.append(l)
for k in range(2**D):
    value = 0
    b = format(k,'b').zfill(D)
    l = list(map(int,list(b)))
    cnt = 0
    for i in range(D):
        if l[i]:
            L[i][2] = 1
            value += L[i][1]
            value += L[i][0]*((i+1)*100)
            cnt += L[i][0]
        else:
            L[i][2] = 0
    remain = list(filter(lambda x:x[2]==0,L))[::-1]
    j = len(remain)
#    print(value,cnt,remain)
    if G - value > 0:
        while True:
            if remain==[]:
                cnt = 10**100
                break
            tmp = remain.pop(0)
            if G - value <= (j*100)*(tmp[0] - 1):
 #               print(G-value,j*100)
                cnt += ceil((G-value)/(j*100))
                break
            else:
                cnt += tmp[0]-1
                value += (j*100)*(tmp[0]-1)
                j -= 1
    ans.append(cnt)

print(min(ans))
