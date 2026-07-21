d = {'m':1000,'c':100,'x':10,'i':1}
k = ['i','x','c','m']
def digit(s):
    r,p = 0,1
    for x in s:
        if x.isdigit(): p = int(x)
        else:
            r += p*d[x]
            p = 1
    return r

for _ in range(int(input())):
    a,b = input().split()
    s = digit(a)+digit(b)
    r = []
    for i,x in enumerate(reversed(str(s))):
        if x!='0': r += [x+k[i]] if x!='1' else [k[i]]
    print(*reversed(r),sep='')
