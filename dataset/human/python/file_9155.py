import re

s = input()
ptn = re.compile(r'maerd|remaerd|resare|esare')
tmp = s[::-1]

while(True):
  res = re.match(ptn , tmp)
  if res is None:
    break
  tmp = tmp.replace(res.group(),'',1)

if len(tmp) == 0:
  print('YES')
else:
  print('NO')
