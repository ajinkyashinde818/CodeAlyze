s = input()
t = input()
s1 = [str(a) for a in s]
t1 = [str(a) for a in t]
s1.sort()
t1.sort()
import copy
t2 = copy.copy(t1)
for i in range(len(t1)):
  t1[i] = t2[len(t1)-i-1]

n = 0
l = 0
i = 0
while n==0 and i <= min(len(t),len(s))-1:
  if s1[i] == t1[i]:
    l = l + 1
    i = i + 1
  elif s1[i] < t1[i]:
    n = n + 1
    print('Yes')
  elif s1[i] > t1[i]:
    n = n + 1
    print('No')
if l == len(t) and len(t) <= len(s):
  print('No')
elif l == len(s) and len(s) < len(t):
  print('Yes')
