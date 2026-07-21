N = int(input())

answer = {(i-1)*i//2:i for i in range(2,500)}

from itertools import combinations


if N not in answer:
  print('No')
  exit()

else:
  print('Yes')

  k = answer[N]
  S = [set() for _ in range(k)]
  for i, c in enumerate(combinations(S,2)):
    for s in c:
      s.add(i+1)

  print(len(S))
  for s in S:
    print(str(len(s)) + ' ' + ' '.join(map(str, list(s))))
