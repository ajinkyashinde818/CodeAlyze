n,k = map(int,input().split())
a = [0]+list(map(int,input().split()))

def bin(arr,val):
    left,right = 0,len(arr)-1
    while left<=right:
        mid = (left+right)//2
        if arr[mid]==val: return 1
        elif arr[mid]<val: left = mid + 1
        else: right = mid - 1
    return 0

know = []
now = 1
while not bin(know, now):
    know.append(now)
    now = a[now]

start = a[know[-1]]
for i,num in enumerate(know):
    if num == start: loop = know[i:] ; break

ans = know[k] if k<len(know) else loop[(k-len(know))%len(loop)]
print(ans)
