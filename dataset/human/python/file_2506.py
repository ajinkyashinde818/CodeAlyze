import sys
input = sys.stdin.readline

def ceil(a, b):
    if a%b == 0:
        return a//b
    else:
        return (a//b) + 1

def main():
    D, G = map(int, input().split())
    pc = [list(map(int, input().split())) for i in range(D)]

    ans = int(1e9)
    for i in range(2**D):
        score = 0
        count = 0
        check = [False] * D
        for j in range(D):
            p, c = pc[j]
            if i&1:# 問題jを全て解く
                score += 100 * (j+1) * p + c
                count += p
                check[j] = True
            i >>= 1
        if score < G:
            for j in range(D):
                if not check[D-1-j]:
                    check[D-1-j] = True
                    p, c = pc[D-1-j]
                    tmp = ceil(G - score, (D-j) * 100)
                    if tmp < p:
                        count += tmp
                        score += tmp * (D-j) * 100
                    break
        if score >= G:
            # print(score, check, count)
            ans = min(ans, count)
    
    print(ans)




if __name__ == "__main__":
    main()
