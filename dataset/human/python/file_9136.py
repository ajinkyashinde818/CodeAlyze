import sys
s = list(input())
while(len(s) > 0):
    if (''.join(s[-5:]) == 'dream'):
        for i in range(5):
            s.pop()
    elif (''.join(s[-5:]) == 'erase'):
        for i in range(5):
            s.pop()
    elif (''.join(s[-6:]) == 'eraser'):
        for i in range(6):
            s.pop()
    elif (''.join(s[-7:]) == 'dreamer'):
        for i in range(7):
            s.pop()
    else:
        print('NO')
        sys.exit()
print('YES')
