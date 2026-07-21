import sys

x = sys.stdin.readline()
x = x.split(' ')
(k,n)=[int(str) for str in x]

x = sys.stdin.readline()
x = x.split(' ')
a=[int(str) for str in x]

prev = 0
amax = 0
sa = 0
for i in range(0,n):
  if(i == 0):
    prev = a[i]
  else:
    among = a[i] - prev
    if( amax < among):
      amax = among
    prev = a[i]
    sa += among

last = a[0] + k - a[n-1]
if( amax < last):
  amax = last
sa += last

print(sa-amax)

sys.stdout.flush()
