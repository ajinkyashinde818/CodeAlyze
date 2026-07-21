import itertools
n = int(input())
s = input()

memo = {}
for i in range(len(s)):
  if s[i] not in memo:
    memo[s[i]] = 1
  else:
    memo[s[i]] += 1
 
li = []
for i in memo.values() :
  li.append(i)

ans = 1
for i in li:
  ans = (ans*(i+1))%1000000007
print((ans-1)%1000000007)
