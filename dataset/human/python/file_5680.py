s = raw_input()

def precheck():
    res = ""
    for c in s:
        if c != "x":
            res += c
    if not res:
        return 1
    if res != "".join(reversed(res)):
        return 0
    return res



def calc(ns):
    lf = ""
    rf = ""
    
    vtype = len(ns) % 2

    pos = 0

    cnt = 0
    while cnt < len(ns)/2:
        lf += s[pos]
        if s[pos] == "x":
            pass
        else:
            cnt+=1
        pos+=1
    
    if vtype:
        while s[pos] == "x":
            lf += s[pos]
            pos+=1
        pos+=1
    else:
         while s[pos] == "x":
            pos+=1

   

    rf = "".join(reversed(s[pos:]))


    lx = 0
    rx = 0
    res = 0
    while 1:

        if lx >= len(lf):
            res += len(rf)-rx
            break
        if rx >= len(rf):
            res += len(lf)-lx
            break

        rrr = rf[rx] == "x"
        lll = lf[lx] == "x"

        if rrr and lll:
            rx+=1
            lx+=1
        elif rrr and not lll:
            rx += 1
            res += 1
        elif not rrr and lll:
            lx += 1
            res += 1
        else:
            rx += 1
            lx += 1
    return res

pc = precheck()
if pc == 1:
    print 0
elif not pc:
    print -1
else:
    print calc(pc)
