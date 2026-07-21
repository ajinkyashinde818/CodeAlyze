from collections import deque
 
S = input()
Q = int(input())
S = deque(S)


flg_reverse = False
for q in range(Q):
  _ = input()
  if _[0] == '1':
    flg_reverse = flg_reverse ^ True
  else:
    _T, _F, _C = _.split()
    if (_F == '1') ^ flg_reverse:
      S.appendleft(_C)
    else:
      S.append(_C)        

S = list(S)
# reverseの部分を対応
if flg_reverse:
  S.reverse()

print(''.join(S))
