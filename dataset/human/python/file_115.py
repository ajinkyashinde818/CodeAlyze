R,G,B,n=map(int,input().split())
def cou(R,G,B,n):
    c=0
    for i in range(n+1):
        r=R*i
        if r>n:
            break
        for j in range(n+1):
            g=G*j
            if r+g>n:
                break
            b=n-r-g
            if b%B==0:
                c+=1
    return c
print(cou(R,G,B,n))
