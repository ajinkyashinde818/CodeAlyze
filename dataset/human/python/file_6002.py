def main1(N, lstA, lstB, lstC):
    bounus = 0
    for i in range(0, len(lstA)-1):
        if (lstA[i] + 1) == lstA[i+1]:
            bounus += lstC[lstA[i]-1]
    print(sum(lstB) + bounus)

N = int(input())
lstA = list(map(int, input().split()))
lstB = list(map(int, input().split()))
lstC = list(map(int, input().split()))
main1(N, lstA, lstB, lstC)
