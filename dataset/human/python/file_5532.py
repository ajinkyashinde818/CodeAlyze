X,Y = (str(i) for i in input().split())

def odd16(Z):
    if Z == 'A':
        return(11)
    elif Z == 'B':
        return(12)
    elif Z == 'C':
        return(13)
    elif Z == 'D':
        return(14)
    elif Z == 'E':
        return(15)
    elif Z == 'F':
        return(16)
    
x = odd16(X)
y = odd16(Y)

if x == y:
    print('=')
elif x > y:
    print('>')
else:
    print('<')
