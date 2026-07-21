def horizontal_input(T=str):
    return list(map(T,input().split()))

def vertical_input(n,T=str,sep=False,septype=tuple):
    data=[]
    if sep:
        for i in range(n):
            data.append(septype(map(T,input().split())))
    else:
        for i in range(n):
            data.append(T(input()))
    return data

d='abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
while 1:
    n=int(input())
    if n==0:
        break
    data=horizontal_input(int)
    s=input()
    ans=[]
    i=0
    for c in s:
        ans.append(d[d.find(c)-data[i]])
        i=(i+1)%len(data)
    print(''.join(ans))
