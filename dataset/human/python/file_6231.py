def main():
    n=list(map(int,list(input())[::-1]))+[0]
    nl=len(n)
    ans=0
    for i in range(nl-1):
        if n[i]>=6 or (n[i]==5 and n[i+1]>=5):
            n[i]=10-n[i]
            n[i+1]+=1
    print(sum(n))
      
if __name__ == '__main__':
    main()
