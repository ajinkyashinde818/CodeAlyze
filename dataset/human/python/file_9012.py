import sys
def DFS(list,s,t):
    if s==t:
        print("YES")
        sys.exit()
    if not t in s:
        return

    for i in list:
        DFS(list,s,t+i)

list=["maerd","remaerd","esare","resare"]
s=input()
s=s[::-1]
t=""
c_index=0
while True:
    moto=c_index
    for i in list:
        index=0
        temp=c_index
        while index<len(i) and temp<len(s) and i[index]==s[temp]:
            index+=1
            temp+=1
        if index==len(i):
            c_index=temp
            break
    if c_index==len(s):
        print("YES")
        sys.exit()
    if c_index==moto:
        print("NO")
        sys.exit()
