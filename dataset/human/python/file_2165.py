import strutils, algorithm, sequtils

let
    DG = stdin.readline().split().map(parseInt)
    D = DG[0]
    G = DG[1]

var
    res = 1000000
    pc = mapIt(0..<D, stdin.readLine().split().map(parseInt))
    p_seq = newSeq[int]()
    c_seq = newSeq[int]()

for vec in pc:
    p_seq.add(vec[0])
    c_seq.add(vec[1])

for bit in 0..<(1 shl D):
    var
        ans = 0
        num = 0

    for i in 0..<D:
        if (bit and (1 shl i)) != 0:
            ans += p_seq[i]*(i+1)*100 + c_seq[i]
            num += p_seq[i]
    if ans >= G:
        res = min(num, res)
    else:
        for i in countdown(D-1, 0):
            #echo $i
            if (bit and (1 shl i)) != 0:
                continue
            else:
                for j in 0..<p_seq[i]:
                    if ans >= G:
                        break
                    ans += 100*(i + 1)
                    num += 1
                        

    res = min(num, res)
    
echo res
