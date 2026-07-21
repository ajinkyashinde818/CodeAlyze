D, G = map(int,input().split())
Q=[0]+[list(map(int,input().split())) for i in range(D)]

def ans(a,b):
  if a==0:
    return 10**9
  n = min(b//(a*100), Q[a][0])
  score = a*100*n
  if n == Q[a][0]:
    score += Q[a][1]
  if score < b:
    n += ans(a-1, b-score)
  n = min(n, ans(a-1,b))
  return(n)

print(ans(D,G))
