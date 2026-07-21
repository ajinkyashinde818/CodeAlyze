def main():
    s=input()
    l=len(s)
    i,j=0,l-1
    ans,cnti,cntj=0,0,0
    while i+1<j:
        if s[i]=='x':
            i+=1
            cnti+=1
        elif s[j]=='x':
            j-=1
            cntj+=1
        else:
            if s[i]==s[j]:
                ans+=abs(cnti-cntj)
                cnti,cntj=0,0
                i+=1
                j-=1
            else:
                print(-1)
                exit()
    if i==j:
        print(ans)
    else:
        if s[i]==s[j]:
            print(ans)
        else:
            if s[i]=='x':
                print(ans+abs(cnti+1-cntj))  
            elif s[j]=='x':
                print(ans+abs(cnti-cntj-1))
            else:
                print(-1)          
    
if __name__=='__main__':
    main()
