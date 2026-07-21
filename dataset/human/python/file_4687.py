def mcxiToDigit(s):
    s="1"+s
    num=0
    dic={"m":1000,"c":100,"x":10,"i":1}
    for c in dic:
        if c in s:
            if "2"<=s[s.index(c)-1]<="9":
                num+=int(s[s.index(c)-1])*dic[c]
            else:
                num+=dic[c]
    return num

for i in range(input()):
    L=raw_input().split()
    sm=mcxiToDigit(L[0])+mcxiToDigit(L[1])
    T=((1000,"m"),(100,"c"),(10,"x"),(1,"i"))
    s=""
    for d,c in T:
        val=sm/d
        if val>1:
            s+=str(val)+c
        elif val==1:
            s+=c
        sm%=d
    print s
