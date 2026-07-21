import re

S = input()
T = []

a = re.split('eraser', S)
a1 = ''.join(a)
a2 = re.split('erase', a1)
a3 = ''.join(a2)
a4 = re.split('dreamer|dream', a3)
a5 = ''.join(a4)

if(a5 == ''):
    print('YES')
else:
    print('NO')
