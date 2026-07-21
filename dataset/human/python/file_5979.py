def main():
    n = int(input())
    aa = list(map(int, input().split()))
    bb = list(map(int, input().split()))
    c = list(map(int, input().split()))
    ans=0
    pre=-1
    for i,(a,b) in enumerate(zip(aa,bb)):
        ans+=b
        if a==pre+1:
            ans+=c[a-2]
        pre=a
    print(ans)

main()
