def main():
  n,k,*a = map(int,open(0).read().split())
  c = [0]
  visit = [False]*n
  visit[0] = True
  for i in range(n):
    nt = a[c[-1]]-1
    if visit[nt]:
      ws = c.index(nt)
      wst = c[:ws]
      wrt = c[ws:]
      wr = len(wrt)
      break
    else:
      c.append(nt)
      visit[nt] = True
  if ws > k:
    ans = wst[k]
  else:
    ans = wrt[(k-ws)%wr]
  print(ans+1)
main()
