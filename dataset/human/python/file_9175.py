import sys
input = sys.stdin.readline

s=input().strip()
n=len(s)
s+="###################################"
i=0
while n-i>=1:
    """print(n-i)
    print(s[i:i+5])"""

    if s[i:i+5]=="dream":
        if s[i+5:i+7]=="er":
            #print(s[i+7:i+11])
            if s[i+7:i+10]=="ase":
                if s[i+10]=="r":
                    i+=11
                else:
                    i+=10    
            else:
                i+=7
        else:
            i+=5

    elif s[i:i+5]=="erase":
        #print(8)
        if s[i+5]=="r":
            i+=6
        else:
            i+=5
    else:
        print("NO")
        exit()
print("YES")
