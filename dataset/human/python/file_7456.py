import sys
input = sys.stdin.readline

def sol():
    s=input().rstrip()
    q=int(input())
    x=0
    a,b="",""
    for i in range(q):
        l=tuple([i for i in input().split()])
        if l[0]=="1":
            x=(x+1)%2
        elif l[1]=="1":
            if x==0: a=l[2]+a
            else: b=b+l[2]
        elif l[1]=="2":
            if x==0: b=b+l[2]
            else: a=l[2]+a
    s=a+s+b
    print(s if x==0 else s[::-1])

if __name__=="__main__":
    sol()
