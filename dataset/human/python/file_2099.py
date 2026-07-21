n = int(input())
 
s = input()
 
x = []
 
for i in range(n):
    x.append(s[i])
 
import collections
 
clist = collections.Counter(x)
 
y = list(clist.values())
 
cnt = 1
 
for item in y:
    cnt = cnt * (item + 1)
 
cnt = cnt - 1
cnt = cnt % (10 ** 9 + 7)
print(cnt)
