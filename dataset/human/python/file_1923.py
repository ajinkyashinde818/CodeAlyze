def main():
    n,m = map(int,input().split()) 
    a=[]
    b=[]
    for _ in range(n):
        a.append( list(input()) )
    for _ in range(m):
        b.append( list(input()) )
    key=0
    for i in range(n-m+1):
        for j in range(n-m+1):
            for x in range(m):
                for y in range(m):
                    if b[x][y]==a[i+x][j+y]:
                        continue
                    else:
                        key=1
                        break
                if key==1:
                    break
            if key == 0:
                print("Yes")
                return
            key=0
    print("No")
main()
