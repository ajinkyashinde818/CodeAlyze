s=input()
def check(s):
    if s[-5:]=='dream':
        return 'dream'
    elif s[-7:]=='dreamer':
        return 'dreamer'
    elif s[-5:]=='erase':
        return 'erase'
    elif s[-6:]=='eraser':
        return 'eraser'
    else: return 'False'

count=0
while len(s)>0 and count==0:
    if check(s)=='False':
        count+=1
        print('NO')
    elif check(s)=='dream' or check(s)=='erase':
        s=s[:-5]
    elif check(s)=='eraser':
        s=s[:-6]
    elif check(s)=='dreamer':
        s=s[:-7]

if count==0:print('YES')
