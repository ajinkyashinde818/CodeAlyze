from collections import deque
S=input()
N=len(S)
i=0
flag=1
ans=[]
buf=""
while i<N:
    if (i+9<N)and((S[i]=="d")and(S[i+1]=="r")and(S[i+2]=="e")and(S[i+3]=="a")and(S[i+4]=="m")and(S[i+5]=="e")and(S[i+6]=="r")and(S[i+7]=="a")and(S[i+8]=="s")and(S[i+9]=="e")):
        if i+10==N:
            break
        elif (S[i+10]=="d")or(S[i+10]=="e"):
            i=i+10
        elif (S[i+10]=="r"):
            i=i+5
        else:
            flag=0
            break
    elif (i+6<N)and((S[i]=="d")and(S[i+1]=="r")and(S[i+2]=="e")and(S[i+3]=="a")and(S[i+4]=="m")and(S[i+5]=="e")and(S[i+6]=="r")):
        if i+7==N:
            break
        elif (S[i+7]=="d")or(S[i+7]=="e"):
            i=i+7
        else:
            flag=0
            break
    elif (i+4<N)and((S[i]=="d")and(S[i+1]=="r")and(S[i+2]=="e")and(S[i+3]=="a")and(S[i+4]=="m")):
        if i+5==N:
            break
        elif (S[i+5]=="d"):
            i=i+5
        else:
            flag=0
            break
    elif (i+5<N)and((S[i]=="e")and(S[i+1]=="r")and(S[i+2]=="a")and(S[i+3]=="s")and(S[i+4]=="e")and(S[i+5]=="r")):
        if i+6==N:
            break
        elif (S[i+6]=="e")or(S[i+6]=="d"):
            i=i+6
        else:
            flag=0
            break
    elif (i+4<N)and((S[i]=="e")and(S[i+1]=="r")and(S[i+2]=="a")and(S[i+3]=="s")and(S[i+4]=="e")):
        if i+5==N:
            break
        elif (S[i+5]=="e")or(S[i+5]=="d"):
            i=i+5
        else:
            flag=0
            break
    else:
        flag=0
        break
    #print(i)
    #input()
if flag==1:
    print("YES")
else:
    print("NO")
