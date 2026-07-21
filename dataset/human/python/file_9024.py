import sys

s = input()
s = s[::-1]

if len(s) == 0:
    print('YES')
    sys.exit()

words = ['maerd', 'remaerd', 'esare', 'resare']
can = True

while can:
    can = False
    for word in words:
        if s.startswith(word):
            s = s[len(word):]
            can = True

if len(s) == 0:
    print('YES')
else:
    print('NO')
