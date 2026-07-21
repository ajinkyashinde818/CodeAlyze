def main():
    N,K = map(int,input().split())
    A = list(map(int, input().split()))

    tele_num = 0
    check = [0]*(N+1)
    check[1] = 1
    temp = 1
    i = 2
    roop_num = 0
    sho = 0
    amari = 0

    while i != K+2:
        temp1 = A[temp-1]
        if check[temp1] != 0:
            roop_num = check[temp] - check[temp1] + 1
            tele_num = K + 2 - i - 1
            sho = tele_num // roop_num
            amari = tele_num % roop_num
            break

        check[temp1] = i
        i += 1
        temp = temp1

    #print(roop_num,tele_num,sho,amari)

    j = 0
    temp = temp1
    while j != amari:
        temp1 = A[temp-1]
        #check[temp1] = i
        j += 1
        temp = temp1

    print(temp)
    #print(i,temp, check)

main()
