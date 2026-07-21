import math
def solve():
  d,g = (int(i) for i in input().split())
  query = []
  ans = 10**15
  for i in range(d):
    p,c = (int(i) for i in input().split())
    query.append((p,c,(i+1)*100))
  for i in range(2**d):
    ct = 0
    point = 0
    use = [False]*d
    for j in range(d):
      if (i>>j)&1 == 1:
        use[j] = True

    for m in range(d):
      if use[m]:
        tp,tc,ti = query[m]
        ct += tp
        point += ti*tp+tc
        
    if point >= g:
      ans = min(ans,ct)
    else:
        for l in range(d):
          if use[d-l-1]:
            continue
          else:
            tp,tc,ti = query[d-l-1]
            twant = math.ceil((g-point)/ti)
            if tp >= twant:
              point += twant*ti
              ct += twant

            if point >= g:
              ans = min(ans,ct)
              break


            

  print(ans)
    
    
solve()
