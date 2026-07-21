def main():

    N = int(input())

    k=0
    while True:
        t=k*(k+1)//2
        if t==N:
            break
        if t>N:
            print("No")
            return
        k+=1

    print("Yes")
    print(k+1)

    sets=[list() for j in range(k+1)]
    x=0
    y=1
    for i in range(1,N+1):
        sets[x].append(i)
        sets[y].append(i)
        x+=1
        if y==x:
            y+=1
            x=0

    # 出力
    for s in sets:
        u=" ".join(str(ss) for ss in s)
        print("{} {}".format(len(s), u))

if __name__ == '__main__':
    main()
