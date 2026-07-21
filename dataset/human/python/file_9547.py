import collections
 
n,k = list(map(int,input().split()))
a = list(map(int,input().split()))
a = [int(i)-1 for i in a]
 
ex = collections.defaultdict(lambda:-1)
step=1
cur=0
ex[0]=0
while 1:
    if ex[a[cur]]!=-1:
        cycle = step-ex[a[cur]]
        k-=ex[a[cur]]-1
        #print(k%cycle)
        break
    else:
        if step==k:
            print(a[cur]+1)
            exit()
        ex[a[cur]]=step
        cur=a[cur]
    step+=1

#print(ex,k%cycle)
for i in range(k%cycle):
    cur = a[cur]
print(cur+1)
