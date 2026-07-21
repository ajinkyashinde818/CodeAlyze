def func():
    D, G = map(int, input().split())
    p = [0] * D 
    bonus = [0] * D
    for i in range(D):
        p[i], bonus[i] = map(int, input().split())
    
    ans = 10000
    for i in range(2 ** D):
        chosen = []
        for j in range(D):
            if ((i >> j) & 1) == 1:
                chosen.append(j)
        
        pointSum = 0
        Nsolved = 0
        for idx in chosen:
            pointSum += (idx + 1) * 100 * p[idx] + bonus[idx]
            Nsolved += p[idx]
        
        if pointSum >= G:
            ans = min(ans, Nsolved)
        else:
            notChosen = list(filter(lambda x: x not in chosen, list(range(D))))
            highestDimIdx = notChosen[-1]
            # if pointSum + (highestDimIdx + 1) * 100 * (p[highestDimIdx]-1) >= G:
            #     rest = G - pointSum
            #     Nsolved += -(-(rest // ((highestDimIdx + 1) * 100)))
            #     ans = min(ans, Nsolved)

            Nsolved += min(p[highestDimIdx] - 1, -(-(G - pointSum) // ((highestDimIdx + 1) * 100)))
            pointSum += min(p[highestDimIdx] - 1, -(-(G - pointSum) // (highestDimIdx + 1 * 100))) * (highestDimIdx + 1) * 100
            
            if pointSum >= G:
                ans = min(ans, Nsolved)
            

    print(ans)
        
if __name__ == '__main__':
    func()
