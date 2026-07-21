import sys
S="".join(reversed(input()))
i=0
while i<len(S):
    if i+4<len(S) and (S[i:i+5]=="maerd" or S[i:i+5]=="esare"):
        i+=5
    elif i+5<len(S) and (S[i:i+6]=="resare"):
        i+=6
    elif i+6<len(S) and (S[i:i+7]=="remaerd"):
        i+=7
    else:
        print("NO")
        sys.exit()
print("YES")
