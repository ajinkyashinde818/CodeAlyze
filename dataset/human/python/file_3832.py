def soinsu(n):
    insu = []
    tmp = n
    if n == 1:
        insu.append([1,0])
        return insu
    for i in range(2,int(n**0.5)+1):
        cnt = 0
        if tmp % i == 0:
            while(tmp % i == 0):
                tmp //= i
                cnt += 1
            insu.append([i,cnt])
    if tmp != 1:
        insu.append([tmp,1])
    if len(insu) == 0:
        insu.append([n,1])
    return insu

n = int(input())
a = [0]*(int(n**0.5)+1)
cnt=1
for i in range(1,len(a)):
    for j in range(cnt,cnt+i+1):
        if j < len(a):
            a[j] = i
            cnt += 1
        else:
            break
sum = 0
insu = soinsu(n)

for i in range(len(insu)):
    sum += a[insu[i][1]]
print(sum)
