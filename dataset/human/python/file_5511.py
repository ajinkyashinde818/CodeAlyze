def changer(x):
    if x=='A':
        return 1
    elif x=='B':
        return 2
    elif x=='C':
        return 3
    elif x=='D':
        return 4
    elif x=='E':
        return 5
    elif x=='F':
        return 6
    else:
        return 0
a,b=map(str,input().split())
if changer(a)>changer(b):
    print('>')
elif changer(a)==changer(b):
    print('=')
else:
    print('<')
