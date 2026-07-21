N=int(input())
def factorize(n):
    b = 2
    fct = []
    while b * b <= n:
        while n % b == 0:
            n //= b
            fct.append(b)
        b = b + 1
    if n > 1:
        fct.append(n)
    return fct
a=factorize(N)

q={}
for i in range(len(a)):
  if a[i] in q:
    q[a[i]]+=1
  else:
    q[a[i]]=1
def k(n):
    B=[i*(i+1) for i in range(20)]
    s=0
    for j in range(20):
      if 2*n>=B[j]:
        s=j
      else:
        s=s
    return s
c=0
for key in q.keys():
  c+=k(q[key])
print(c)
