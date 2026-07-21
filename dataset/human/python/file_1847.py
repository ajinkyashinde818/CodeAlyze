import sys
def main():
    t = sys.stdin.readline()
    t1 = t.rstrip()
    t2 = t1.split(' ')
    stra = [] 
    for i in range(int(t2[0])):
        y = sys.stdin.readline()
        t = y.rstrip()
        stra += [t]
    strb = [] 
    for i in range(int(t2[1])):
        y = sys.stdin.readline()
        t = y.rstrip()
        strb += [t]
 
    suma = 0
    for x in strb:
        for y in stra:
            if x in y:
                suma +=1 
    if int(t2[0])*int(t2[1])==suma:
        print("Yes")
    else:
        print("No")
main()
