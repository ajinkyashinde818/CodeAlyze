s=input()
l=len(s)
def len_s(l,n):
    return l-n+1

def get_tail(s,n,number):
    if n==0:
        return s[-number:]
    else:
        return s[-number-n:-n]


    
def check(s,n):
    tail=get_tail(s,n,3)
    if tail=="eam" and len_s(l,n)>=5:
        if get_tail(s,n,5)=="dream":
            return True,n+5
        else:
            return False,None
    elif tail=="mer" and len_s(l,n)>=7:
        if get_tail(s,n,7)=="dreamer":
            return True,n+7
        else:
            return False,None
    elif tail=="ase" and len_s(l,n)>=5:
        if get_tail(s,n,5)=="erase":
            return True,n+5
        else:
            return False,None
    elif tail=="ser" and len_s(l,n)>=6:
        if get_tail(s,n,6)=="eraser":
            return True,n+6
        else:
            return False,None
    else:
        return False,None
ans=0
tail=0
while True:
    bool,tail=check(s,tail)
    if bool:
        if tail==l:
            break
    else:
        ans+=1
        break   
if ans==0:
    print("YES")
else:
    print("NO")
