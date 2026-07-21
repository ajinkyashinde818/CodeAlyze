N,K=[int(x) for x in input().split()]
A=[int(x) for x in input().split()]

def go(i, step):
  prevI=i
  m=[0]*N
  cnt=0
  for s in range(step):
    if m[i]:
      period=m[prevI] - m[i] + 1
      return go(i, (step-s) % period)
    cnt+=1
    m[i]=cnt
    prevI=i
    i=A[i]-1
  return i

print(go(0,K)+1)
