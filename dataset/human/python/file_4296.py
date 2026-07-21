n=int(input())
if n==1:
    print(0)
else:
    def fac(n):
        arr=[]
        temp=n
        for i in range(2,int(-(-n**0.5//1))+1):
            if temp%i==0:
                cnt=0
                while temp%i==0:
                    cnt+=1
                    temp//=i
                arr.append(cnt)
        if temp!=1:
            arr.append(1)
        if arr==[]:
            arr.append(1)
        return arr
    anss=fac(n)
    dic={}
    ans=0
    for i in anss:
        if i in dic:
            ans+=dic[i]
        elif i==1:
            dic[i]=1
            ans+=1
        else:
            j=i
            ansss=0
            cou=1
            while j>=cou:
                ansss+=1
                j-=cou
                cou+=1
            ans+=ansss
            dic[i]=ansss
    print(ans)
