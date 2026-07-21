def updiv(a,b):

    if a % b == 0:
        return a // b
    else:
        return a // b + 1


D,G = map(int,input().split())

pc = []

for i in range(D):

    p,c = map(int,input().split())

    pc.append([i+1,p,c])

pc.reverse()

ans = float("inf")

for j in range(2 ** D):

    j_bin = format(j,'b')
    flags = j_bin.zfill(D)

    num = 0
    score = 0

    for k in range(D):

        if flags[k] == "1":

            num += pc[k][1]
            score += pc[k][1] * pc[k][0] * 100 + pc[k][2]

    if G > score:

        for k in range(D):

            if flags[k] == "0" and score + pc[k][1] * pc[k][0] * 100 >= G:

                plnum = updiv( G - score , pc[k][0] * 100 )
                num += plnum

                score += plnum * pc[k][0] * 100
                break

    if G <= score:

        ans = min(ans,num)
        #print (ans,num,score,flags)

print (ans)
