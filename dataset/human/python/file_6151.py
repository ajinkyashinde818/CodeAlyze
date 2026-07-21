def getNumber(string):
    i=0
    while(string[i]!=" "):
        i+=1
    return string[0:i],string[i+1:]
raw = str(input())
a,raw= getNumber(raw)
b,raw= getNumber(raw)
a = int(a)
b = int(b)
c = int(raw)

if(a+b>c):
    print(b+c)
elif(a+b<c):
    print(a+b+1+b)
elif(a+b==c):
    print(c+b)
