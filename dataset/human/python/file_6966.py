import sys

def ep(*params):
    print(*params,file=sys.stderr)

l = ''
r = ''

S = input().rstrip()

Q = int(input())
mode = 0
for _ in range(Q):
    ope = list(input().split())
    if ope[0] == '1':
        mode = (mode + 1)%2
    else:
        op = (int(ope[1]) + mode)%2
        if op == 1:
            l += ope[2]
        else:
            r += ope[2]
    #print(mode,l[::-1],S,r,sep=":",file=sys.stderr)    

if mode == 0:
    print(l[::-1],S,r,sep="")    
else:
    print(r[::-1],S[::-1],l,sep="")
