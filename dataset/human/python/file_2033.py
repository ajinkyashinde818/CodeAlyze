import numpy as np

N = int(input())
S = input()
alpha = np.zeros(52)
Alp = [chr(i) for i in range(97, 97+52)]
for s in S:
  alpha[Alp.index(s)] += 1
alpha = alpha[np.nonzero(alpha)]
def func(alpha):
  Size = alpha.shape[0]
  ans = 0
  if Size>1:
    size=int(Size/2)
    m_ans = func(alpha[:size])
    u_ans = func(alpha[size:])
    ans = (m_ans+1)*(u_ans+1)-1
  else:
    ans = alpha[0]
  return int(ans)

print(func(alpha)%(10**9+7))
