import math
D,G = map(int,input().split())
p = []
c = []
for i in range(D):
  P,C = map(int,input().split())
  p.append(P)
  c.append(C)

res = float("inf")        
for i in range(2**D):
  bs = format(i,"0{}b".format(D))
  ans = 0
  cnt = 0
  #コンプするやつをたす
  for j in range(D):
    if bs[j] == "1":
      ans += (j+1)*100*p[j] + c[j]
      cnt += p[j]
  if ans >= G:
    res = min(cnt,res)
    continue

  #コンプしないやつを寸止めでたす
  for j in range(D-1,-1,-1):
    if bs[j] == "0":
      ans += (j+1)*100*(p[j]-1)
      cnt += (p[j]-1)
      if ans >= G:
        cnt -= (ans-G)//((j+1)*100)
        res = min(res,cnt)
        break
print(res)
