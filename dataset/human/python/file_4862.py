import math

def A():
    a, b = [int(x) for x in input().split()]
    print(math.ceil((a + b)/2))

def B():
    a = ''.join(sorted(list(input()), key=lambda x:ord(x)))
    b = ''.join(sorted(list(input()), key=lambda x:-ord(x)))
    if a < b:
        print('Yes')
    else:
        print('No')

B()
