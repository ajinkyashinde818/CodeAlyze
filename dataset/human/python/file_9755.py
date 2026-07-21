from collections import deque
n,k=map(int, input().split())

A = deque(map(int, input().split()))
li = []
li2 = [0]*n
li.append(1)

next = 0

t=0
rep = False

for i in range(k):
    if i == k:
        print(next+1)
        exit()

    if li2[next] == 1:
        t = li.index(next+1)
        rep = True
        li.pop()
        break

    li.append(A[next])
    li2[next] = 1
    next = A[next]-1


tmp = (k-t)%len(li[t:])
print(li[tmp+t])
