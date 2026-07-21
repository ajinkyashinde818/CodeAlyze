from collections import defaultdict
n, k = map(int,input().split())
a = list(map(int,input().split()))

cnt = defaultdict(lambda :0)
num = defaultdict(lambda :0)
cnt[1] = 1
num[1] = 1
trans = 1
for i in range(k):
    temp = a[trans - 1]
    #print(temp)
    if cnt[temp] != 0:
        roop = - cnt[temp] + cnt[trans] + 1
        omit = (k - cnt[temp] + 1) % roop

        ans = num[cnt[temp] + omit]
        print(ans)
        exit()
    cnt[temp] = cnt[trans] + 1
    num[cnt[temp]] = temp
    trans = temp

print(trans)
