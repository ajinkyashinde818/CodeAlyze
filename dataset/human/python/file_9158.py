import sys

s = input()
s = s[::-1]

d ='maerd'
dr = 'remaerd'
e = 'esare'
er = 'resare'

i = 0
while True:
    try:
        if s[i:i+5] == d or s[i:i+5] == e:
            i += 5
            if i == len(s):
                print('YES')
                sys.exit(0)
        
        elif s[i:i+6] == er:
            i += 6
            if i == len(s):
                print('YES')
                sys.exit(0)
        
        elif s[i:i+7] == dr:
            i += 7
            if i == len(s):
                print('YES')
                sys.exit(0)
            
        else:
            print('NO')
            sys.exit(0)
            
    except Exception as err:
        print('NO')
        sys.exit(0)
