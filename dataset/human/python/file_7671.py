from collections import deque
 
S = deque(input())
Q = int(input())
 
Q_list = [list(map(str, input().split())) for i in range(Q)]
 
rev = False
 
for i in range(Q):
  if int(Q_list[i][0]) == 1:
    rev = not rev
  
  else:
    F = Q_list[i][1]
    C = Q_list[i][2]
    
    if rev ^ (int(F) == 1): # 排他的論理和片方真片方ぎの時真になる
      S.appendleft(C) # 反転している場合は、末尾、先頭追加を逆にする
    else:
      S.append(C)
      
if rev: # 最終的に反転している場合は反転させる
  S.reverse()
  
print(''.join(S))
