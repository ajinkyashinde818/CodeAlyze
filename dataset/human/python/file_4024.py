def prime_f(n,p=2):
    if n==1:
        return []
    while True:
        if n<p**2:
            return [n]
        if n%p==0:
            l=prime_f(n//p,p)
            l.append(p)
            return l
        p+=1


def histo_list(lis):
    if lis==[]:
        return []
    new=[[lis[0],1]]
    d=lis[0]
    for c in range(1,len(lis)):
        if lis[c]!=d:
            new.append([lis[c],1])
            d=lis[c]
        else:
            new[-1][1]+=1
    return new


n=int(input())
a=prime_f(n)
a=a[::-1]
b=histo_list(a)
c=[b[x][1] for x in range(len(b))]
s=0
for x in c:
    s+=((8*x+1)**0.5-1)//2
print(int(s))
