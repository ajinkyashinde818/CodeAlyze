import copy

N, C= map(int,input().split())
XV = sorted([list(map(int,input().split())) for _ in range(N)])
acmXV = []
dbl_acmXV = []

for i, xv in enumerate(XV):
  x,v = xv
  if i == 0:
    acmXV.append(v-x)
    dbl_acmXV.append(v-x*2)
  else:
    acmXV.append(v-(x-XV[i-1][0])+acmXV[i-1])
    dbl_acmXV.append(v-(x-XV[i-1][0])*2+dbl_acmXV[i-1])

acmXV_rev = [0 for _ in range(N)]
dbl_acmXV_rev = [0 for _ in range(N)]
for i in range(N-1, -1, -1):
  x,v = XV[i]
  if i == N-1:
    acmXV_rev[i] = v-(C-x)
    dbl_acmXV_rev[i] = v-(C-x)*2
  else:
    acmXV_rev[i] = (v-(XV[i+1][0]-XV[i][0])+acmXV_rev[i+1])
    dbl_acmXV_rev[i] = (v-(XV[i+1][0]-XV[i][0])*2+dbl_acmXV_rev[i+1])


max_acmXV_rev = copy.deepcopy(acmXV_rev)
max_dbl_acmXV_rev = copy.deepcopy(dbl_acmXV_rev)
for i in range(N-2,-1,-1):
  max_acmXV_rev[i] = max(max_acmXV_rev[i], max_acmXV_rev[i+1])
  max_dbl_acmXV_rev[i] = max(max_dbl_acmXV_rev[i],max_dbl_acmXV_rev[i+1])

ans = max(0,max(acmXV),max(acmXV_rev))
for i in range(N-1):
  ans = max(ans, dbl_acmXV[i]+max_acmXV_rev[i+1], acmXV[i]+max_dbl_acmXV_rev[i+1]) 
print(ans)
