def main():

    n = int(input())
    a = list(map(int,input().split()))
    cnt_mns = 0
    mini = 10000000000
    sm = 0
    for i, aa in enumerate(a):
        if aa < 0:
            cnt_mns += 1

        if abs(aa) < mini:
            mini = abs(aa)
        sm += abs(aa)
    if cnt_mns % 2 == 1:
        print(sm - 2 * mini)
        
    else:
        print(sm)




if __name__ == '__main__':


    main()
