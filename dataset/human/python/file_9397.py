import sys;input=lambda:sys.stdin.readline().rstrip();ints=lambda:list(map(int,input().split()))

def main():
    n,k=ints()
    a=ints()
    passed=[]
    flg,p=0,0
    while flg==0:
        if a[p] == 'p':
            flg=1
            s=passed.index(p)
            break
        else:
            passed.append(p)
            pp=p
            p=a[pp]-1
            a[pp]='p'
    l=len(passed)
    print(passed[k]+1) if k<l else print(passed[(k-s)%(l-s)+s]+1)

if __name__ == '__main__':
    main()
