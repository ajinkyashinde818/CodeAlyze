from collections import deque
D,G = [int(i) for i in input().split()]
P = [0]*D
n = 0
for i in range(D):
    p,c = [int(j) for j in input().split()]
    P[i] = [int(k) * 100 * (i+1) for k in range(p+1)]
    P[i][-1] += c
    n += p
deq = deque()
ans = n
deq.append((0,0,0))
dic = {}

while(len(deq)>0):
    tmp = deq.pop()
    if tmp[0]+1 > len(P):
        break
    for i,j in enumerate(P[tmp[0]]):
        cand = (tmp[0]+1, tmp[1]+i, tmp[2]+j)
        if cand[1] < ans:
            if cand[2] < G:
                if cand[1] not in dic:
                    dic[cand[1]] = cand[2]
                    deq.appendleft(cand)
                elif dic[cand[1]] <= cand[2]:
                    dic[cand[1]] = cand[2]
                    deq.appendleft(cand)
            else:
                ans = cand[1]
print(ans)
