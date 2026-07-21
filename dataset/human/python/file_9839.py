from collections import deque
n,k=map(int, input().split())
a=list(map(int, input().split()))
arr=[-1]*n
arr[0]=0
que=deque([a[0]])
i=1
loop=0

while loop==0:
    x=que.popleft()
    if arr[x-1]==-1:
        arr[x-1]=i
        i+=1
        que.append(a[x-1])
    else:
        loop=i-arr[x-1]
        break
b_loop=i-loop

if k<i:
    print(arr.index(k)+1)
else:
    print(arr.index(b_loop+(k-b_loop)%loop)+1)
