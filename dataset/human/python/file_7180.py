S = input()
S_h = ''
S_t = ''
Q = int(input())

def add_car(S_h,S_t,s,is_left,is_rev):
    if is_rev:
        is_left = not(is_left)
    if is_left:
        S_h = ''.join([S_h,s])
    else:
        S_t = ''.join([S_t,s])
    return S_h,S_t

is_rev = False
for q in range(Q):
    x = input().split(' ')
    if len(x) == 1:
        is_rev = not is_rev
    else:
        S_h,S_t = add_car(S_h,S_t,x[2],x[1]=='1',is_rev)

if is_rev:
    S_t = ''.join(list(reversed(S_t)))
    S = ''.join(list(reversed(S)))
    print(''.join([S_t,S,S_h]))
else:
    S_h = ''.join(list(reversed(S_h)))
    print(''.join([S_h,S,S_t]))
