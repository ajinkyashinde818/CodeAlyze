def main():
    R,B,G,N = list(map(int,input().split(' ')))
    cnt = 0
    for r in range(N//R+1):
        for g in range(N//G+1):
            if R*r+G*g > N:
                break
            if (N-(R*r+G*g))%B ==0:

                cnt +=1
    print(cnt)
if __name__ =='__main__':
    main()
