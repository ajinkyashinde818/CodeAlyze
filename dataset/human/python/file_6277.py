def y_solver(tmp):
    l=len(tmp)
    rev=[int(i) for i in tmp[::-1]+"0"]
    ans=0
    for i in range(l):
        num=rev[i]
        next_num=rev[i+1]
        if (num>5) or (num==5 and next_num>=5):
            rev[i+1]+=1
        ans+=min(num,10-num)  
    last=rev[l]
    ans+=min(last,10-last)
    return ans
s=input()
ans=y_solver(s)
print(ans)
