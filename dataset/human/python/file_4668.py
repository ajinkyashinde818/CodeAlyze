di = {"m":1000,"c":100,"x":10,"i":1}
num = input()

def decod(st):
    buf = 1
    tot = 0
    for i in st:
        if ((i == 'm') or (i == 'c') or (i == 'x') or (i == 'i')):
            tot += buf * di[i]
            buf = 1
        else:
            buf = int(i)
    return tot


def encod(num):
    l = []
    st2 = ""
    st = str(num)
    st = "0"*(4-len(st)) + st
    for i in range(len(st)):
        l.append(st[len(st) - (i + 1):len(st) - i])
    for i in range(len(l)):
        st2 += l[3-i] + di.keys()[3-i]
    st2 = st2.replace("0m", "").replace("1m", "m").replace("0c", "")\
        .replace("1c", "c").replace("0x", "").replace("1x", "x")\
        .replace("0i", "").replace("1i", "i")
    return st2

for j in range(num):
    op1,op2 = raw_input().split()
    print encod(decod(op1)+decod(op2))
