def getNumNeg(L):
  return sum([i<0 for i in L])
  
def findmax2(L):
  numNeg = getNumNeg(L)
  absL = list(map(abs, L))
  if numNeg % 2 == 0:
    print(sum(absL))
  else:
    print(sum(absL)-2*min(absL))
        
n = int(input())
a = list(map(int, input().split()))
findmax2(a)
