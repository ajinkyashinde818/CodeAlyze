D, G = map(int, input().split())
PC = []
for i in range(D):
    p, c = list(map(int, input().split()))
    s = (i+1) * 100
    PC.append([p, c, s])

P = []
for i in range(2 ** D):
    b = format(i, 'b').zfill(D)
    P.append(b)

def get_high_score_q(p):
    if p.count('0') == 0:
        return None
    else:
        pos = []
        for i, pi in enumerate(p):
            if pi == '0':
                pos.append(i)
        return pos[-1]

ans = 10 ** 10
# P: ['00', '01', '10', '11']
for pi in P:
    # print('pi', pi)
    scores = 0
    probs = 0
    for i, b in enumerate(pi):
        if b == '0':
            pass
        elif b == '1':
            pc = PC[i]
            scores += pc[0] * pc[2] + pc[1]
            probs += pc[0]
        else:
            raise Exception()

    # print(scores, probs)
    if scores < G:
        q = get_high_score_q(pi)
        pc = PC[q]
        for i in range(pc[0]):
            scores += pc[2]
            probs += 1
            if scores >= G:
                break
    # print(scores, probs)
    if scores >= G:
        ans = min(ans, probs)

print(ans)
