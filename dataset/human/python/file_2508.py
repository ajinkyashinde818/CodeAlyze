from sys import stdout
printn = lambda x: stdout.write(x)
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
DBG = True  and False
BIG = 999999999
R = 10**9 + 7

def ddprint(x):
  if DBG:
    print(x)

d,g = inm()
p = []
c = []
for i in range(d):
    pp,cc = inm()
    c.append(cc)
    p.append(pp)

mn = BIG
for i in range(2**d):
    s = [0]*d
    for j in range(d):
        s[j] = (i>>j)%2  ## set bit info
    ddprint("i {} s {}".format(i,s))
    np = 0
    sc = 0
    for j in range(d):
        if s[j]==1:
            sc += 100*(j+1)*p[j] + c[j]
            np += p[j]
    ddprint("full sc {} np {}".format(sc,np))
    if sc<g:
      for j in range(d-1,-1,-1): # only 1st non-full j enuf
        if s[j]==1:
            continue
        for k in range(p[j]-1):
            np += 1
            sc += 100*(j+1)
            if sc >= g:
                break
        break
    ddprint("all sc {} np {}".format(sc,np))
    if sc>=g and np<mn:
        mn = np
print(mn)
