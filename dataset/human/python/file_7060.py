from sys import stdout

s = input()
q = int(input())
pref = ''
suff = ''
order = 1
for i in range (q):
  e = input().split()
  if e[0] == '1':
    order *= (-1)
  else:
    if order == 1:
      if e[1] == '1':
        pref = e[2] + pref
      else:
        suff += e[2]
    else:
      if e[1] == '2':
        pref = e[2] + pref
      else:
        suff += e[2]
if order == 1:
    stdout.write(pref)
    stdout.write(s)
    stdout.write(suff)
else:
    stdout.write(suff[::-1])
    stdout.write(s[::-1])
    stdout.write(pref[::-1])
