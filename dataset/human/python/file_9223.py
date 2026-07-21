import sys
s=input()
k="dream"
l="erase" #5文字ペア
m="eraser" #6文字
n="dreamer" #7文字
while True:
    if s=="":
        print("YES")
        sys.exit()
    elif k in s[-5:]:
        s=s[:-5]            
    elif l in s[-5:]:
        s=s[:-5]
    elif m in s[-6:]:
        s=s[:-6]
    elif n in s[-7:]:
        s=s[:-7]
    else:
        print("NO")
        sys.exit()
