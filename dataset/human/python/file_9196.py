import sys
s=''.join(reversed(list(input())))
t=''
text = ['maerd', 'esare', 'resare', 'remaerd']
while len(t) < len(s):
  for tx in text:
    if t + tx == s[:len(t+tx)]:
      t += tx
      break
  else:
    print('NO')
    sys.exit()
print('YES')
