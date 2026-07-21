S = str(input())
def remove_word(S):
  S1 = S
  if S[-5:] == 'dream':
    S1 = S[:-5]
  if S[-7:] == 'dreamer':
    S1 = S[:-7]
  if S[-5:] == 'erase':
    S1 = S[:-5]
  if S[-6:] == 'eraser':
    S1 = S[:-6]
  if S1 != S:
    return S1
  else:
    return'NO'
while len(S)>0:
  S = remove_word(S)
  if S == 'NO':
    break
if S == 'NO':
  print('NO')
else:
  print('YES')
