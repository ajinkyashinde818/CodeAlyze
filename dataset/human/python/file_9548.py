def main():
    N,K  = map(int, input().split()) 
    A = list(map(int, input().split()))  
    A.insert(0,0)
    B = [0]*(N+1)
    tel = 1
    telmae = 1

    for i in range(K):
        if B[tel] ==0:
            B[tel] = i
            telmae = tel
            tel = A[tel]
        else:
            temp =  i - B[tel]
            joyo = (K-B[tel]) % temp
            for j in range(joyo):
                telmae = tel
                tel = A[tel]
            print(tel)
            return


    print(tel)





if __name__ == '__main__':
    main()
