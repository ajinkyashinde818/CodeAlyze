import math
K, S = map(int, input().split())

"""
0<= X<= K でXを選ぶ
このとき Y+ Z= S- X
Yの最小値は，max(0, S- X- K)
Yの最大値は，min(K, S- X)
よってY, Zの選び方はmin(K, S- X)- max(0, S- X- K)+ 1 通り．
Xについて，0<= X<= Kで足し合わせればよい．
"""
ans = 0

for i in range(K+ 1):
  Y_min = max(0, S- i- K)
  Y_max = min(K, S- i)
  if(Y_max>= Y_min):
    ans+= Y_max- Y_min+ 1
    
print(ans)
