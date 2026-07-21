import sys
input = sys.stdin.readline
 
K,S=map(int,input().split())

ans = []
 
for i in range(K+1):
  s_z = S - i

  if s_z < 0:
    pass

  elif K < s_z:
    if (K + 1) > (s_z - K):
      ans.append(K + K - s_z + 1)
      
  else:
    ans.append(s_z + 1)

print(sum(ans))
