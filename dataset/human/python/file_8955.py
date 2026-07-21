S = input()
S = list(S)
s = ''.join(list(reversed(S)))
def main(s):
  l = ["resare", "esare","remaerd", "maerd"]
  for i in l:
    s = s.replace(i, '')
  return s
if main(s) == '':
  print('YES')
elif main(s) != '':
  print('NO')
