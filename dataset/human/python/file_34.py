from sys import stdin
import numpy as np
 
R, G, B, N = map(int,input().split())

lst = sorted([R, G, B], reverse=True)


cnt = 0
var_1 = N
while True: #一番高いものを買う
  var_2 = var_1
  while True: #二番目に高いものを買う
    if var_2 % lst[2] == 0:
      cnt += 1
    var_2 -= lst[1]
    if var_2 < 0:
      break
  var_1 -= lst[0]
  if var_1 < 0:
    break
    
print(cnt)
