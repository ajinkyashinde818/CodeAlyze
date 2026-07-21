import sys

a=input()
b=input()
c=[]
d=[]
for i in range(len(a)):
    c.append(a[i])
for i in range(len(b)):
    d.append(b[i])
c.sort()
d.sort()
d.reverse()
for i in range(min([len(a),len(b)])):
    if(c[i]<d[i]):
        print("Yes")
        sys.exit()
if(len(a)<len(b)):
    if(a==b[0:len(a)]):
        print("Yes")
        sys.exit()
print("No")
