import sys
N,K = map(int,input().split())
tele = list(map(int,input().split()))
k = 1
flag = [0]*N
goal = tele[0]
miti = [1]
while (flag[goal-1])!=1:
    k += 1
    miti.append(goal)
    flag[goal-1] = 1
    goal = tele[goal-1]
    if k == K:
        print(goal)
        sys.exit()

a = miti.index(goal)
loop = k-a
ans = miti[(K-a)%loop+a]

print(ans)
