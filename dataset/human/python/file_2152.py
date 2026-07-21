import collections

n = int(input())
s = input()
cnt = 0
dictionary = {}

for i in range(n)[::-1]:
  if s[i] in dictionary.keys():
    dictionary[s[i]] += 1
  else:
    dictionary[s[i]] = 1
  ch = s[i:]
  tmp_cnt = 1
  for k,v in dictionary.items():
    if k != s[i]:
      tmp_cnt *= (v+1)
  cnt += tmp_cnt % (10**9+7)
print(cnt % (10**9+7))
