from collections import deque
import bisect
m=int(input())
def fa(n):
    arr =deque([])
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr

x=0
count=0
box=[]
for i in range(1,1000):
    box.append(i*(i+1)//2)
# print(box)
for i,j in fa(m):
    # print(i,j)

    count+=bisect.bisect_right(box, j)


print(count)
