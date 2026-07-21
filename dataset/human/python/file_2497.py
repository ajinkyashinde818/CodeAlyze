import math
D, G = map(int, input().split())
PCS = [ list(map(int, input().split())) + [(i+1)*100] for i in range(D)]

def main():
    ans = float('inf')
    for i in range(1<<D): # pattern i
        g = G
        cnt = 0
        for d in range(D):
            if i & (1<<d): # Solve d
                g -= PCS[d][0]*PCS[d][2] + PCS[d][1]
                cnt += PCS[d][0]
        if g<=0:
            ans = min(ans, cnt)
            continue

        # Not done
        for d in range(D-1, -1, -1):
            if i & (1<<d):
                continue # Solved
            # Not yet
            n = math.ceil(g/PCS[d][2])
            if n>=PCS[d][0]:
                break
            g -= n*PCS[d][2]
            cnt += n
            break
        if g<=0:
            ans = min(ans, cnt)

            
    return ans

print(main())
