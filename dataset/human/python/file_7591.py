s=input()
l1=[]
l2=[]
num1=0 #0は反転なし　1はあり
def ap1(str1):
    l1.append(str1)
def ap2(str2):
    l2.append(str2)
nq=int(input())
for i in range(nq):
    q=list(input().split())
    if q[0]=="1":
        num1=(num1+1)%2
    else:
        f=int(q[1])
        if (num1+f)%2==1: #1で先頭 2で末尾
            ap1(q[2])
        else:
            ap2(q[2])
if num1==0:
    ans=""
    for i in range(len(l1)):
        ans+=l1[-1-i]
    ans+=s
    for i in range(len(l2)):
        ans+=l2[i]
else:
    ans=""
    for i in range(len(l2)):
        ans+=l2[-1-i]
    for i in range(len(s)):
        ans+=s[-1-i]
    for i in range(len(l1)):
        ans+=l1[i]
print(ans)
