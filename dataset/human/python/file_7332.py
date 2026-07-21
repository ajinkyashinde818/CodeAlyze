def main():
    S=input()
    Q=int(input())
    Left=[]
    Right=[]

    reverse_flag=0
    for i in range(Q):
        query=input().split()
        if query[0]=="1":
            if reverse_flag==1:
                reverse_flag=0
            else:
                reverse_flag=1
        else:
            if query[1]=="1":
                if reverse_flag==0:
                    Left.append(query[2])
                else:
                    Right.append(query[2])
            else:
                if reverse_flag==0:
                    Right.append(query[2])
                else:
                    Left.append(query[2])

    res=""
    if reverse_flag==0:
        Left.reverse()
        res+="".join(Left)
        res+=S
        res+="".join(Right)

    else:
        Right.reverse()
        res+="".join(Right)
        S=list(S)
        S.reverse()
        res+="".join(S)
        res+="".join(Left)
    print(res)

if __name__=="__main__":
    main()
