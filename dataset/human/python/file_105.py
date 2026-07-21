def solve():
    R,G,B,N = list(map(int,input().split())) 
    RGBs = sorted([R,G,B],reverse=True)
    count = 0
    if N < min(R,G,B):
        pass
    else:
        for i in range(int(N/RGBs[0])+1):
            O = N - i*RGBs[0]
            for j in range(int(O/RGBs[1])+1):
                P = O - j*RGBs[1]
                if P%RGBs[2] == 0:
                    count += 1
    print(count)


solve()
