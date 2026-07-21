def main():
    D,G = map(int,input().split())
    score = []
    for i in range(D):
        p,c = map(int,input().split())
        score.append((p,c))
    ans = 2**60
    for mask in range(2**D):
        s = 0
        num = 0
        rest = -1
        for i in range(D):
            if (mask >> i&1):
                s += 100*(i+1)*score[i][0]+score[i][1]
                num += score[i][0]
            else:
                rest = i
        if s < G:
            s1 = 100*(rest+1)
            need = (G-s+s1-1)//s1
            if need >= score[rest][0]:
                continue
            num += need
        ans = min(ans,num)

    print(ans)
if __name__ == "__main__":
    main()
