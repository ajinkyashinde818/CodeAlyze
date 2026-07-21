K, S = map(int, input().split())

cnt = 0

if S <= 0:
  cnt += 1
else:

  if K >= S:
      cnt+=3

  def cnt2(k, s):
      if 2 * k >= s:
          if s - 1 <= k:
              return s-1
          else:
              return k-(s-k)+1
      else:
          return 0

  cnt+=3*cnt2(K, S)

  for x in range(1, K+1):
      if S-x <=0:
          break
      cnt += cnt2(K, S-x)

print(cnt)
