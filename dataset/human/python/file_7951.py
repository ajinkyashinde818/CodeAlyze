import itertools

s=input()

x=list(itertools.permutations(('a','b','c'),3))
flag=0
for i in range(len(x)):
  if x[i][0]+x[i][1]+x[i][2] == s:
    flag=1

print('Yes' if flag==1 else 'No')
