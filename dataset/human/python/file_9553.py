def main():
    N,K=map(int,input().split())
    A=list(map(int,input().split()))
    cal=0
    time=[0]*N
    town=[]
    roop=[]

    while time[cal]!=2:
        if time[cal]==0:
            town.append(cal)

        else :
            roop.append(cal)

        time[cal]+=1
        cal=A[cal]-1

    if len(town)>K:
        print(town[K]+1)
        return

    else :
        print(roop[(K-(len(town)-len(roop)))%len(roop)]+1)
        return
main()
