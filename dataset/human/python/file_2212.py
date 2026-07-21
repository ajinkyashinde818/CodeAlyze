def main():
    D,G =map(int,input().split())
    pc = [list(map(int,input().split())) for i in range(D)]
    max_D = int("1"*D,2)
    res = float("inf")
    for i in range(max_D,-1,-1):
        ansed_num = 0
        point = 0
        now = format(i,"0"+str(D)+"b")
        #print(now)
        for j in range(len(now)):
            if now[j] == "1":
                #print(j+1)
                ansed_num += pc[j][0]
                point += (j+1) * 100 * pc[j][0] + pc[j][1]
        for j in range(len(now)-1,-1,-1):
            if now[j] == "0":
                ansed_num_this = 0
                while point < G and ansed_num_this < pc[j][0]:
                    ansed_num += 1
                    point += (j+1) * 100
                    ansed_num_this += 1
            #print(ansed_num,point)
            if point >= G:
                if ansed_num < res:
                    res = ansed_num
    print(res)


if __name__ == "__main__":
    main()
