def fac(n):  #nは2以上
    a=[]
    t=n
    if t%2==0:
        count=0
        while t%2==0:
            count+=1
            t//=2
        a.append([2,count])

    for i in range(3,n+1,2):
        if i*i>n:
            break
        if t%i==0:
            count=0
            while t%i==0:
                count+=1
                t//=i
            a.append([i,count])

    if t!=1:
        a.append([t,1])
    
    return a


from sys import stdin
def main():
    #入力
    readline=stdin.readline
    n=int(readline())
    li=fac(n)
    ans=0
    for i in range(len(li)):
        p=li[i][0]
        cnt=1
        while li[i][1]>=cnt:
            ans+=1
            n//=(p**cnt)
            li[i][1]-=cnt
            cnt+=1

    print(ans)

if __name__=="__main__":
    main()
