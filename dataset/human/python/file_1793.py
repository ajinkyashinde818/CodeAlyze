from sys import stdin
def main():
    readline=stdin.readline
    N,M=map(int,readline().split())
    A=[]
    for i in range(N):
        s=readline().strip()
        A.append(s)
    B=[]
    for i in range(M):
        s=readline().strip()
        B.append(s)
    
    for i in range(N-M+1):
        for j in range(N-M+1):  #左上
            flag=True

            for k in range(M):
                for l in range(M):
                    if B[k][l]!=A[k+i][l+j]:
                        flag=False
                        break
                if flag==False:
                    break
            if flag:
                break
        if flag:
            break
    if flag:
        print("Yes")
    else:
        print("No")
        
if __name__=="__main__":
    main()
