def slove(n, ab_list):

    hoge = {}
    for i,j in ab_list:
        if int(i) not in hoge:
            hoge[int(i)] = []
        hoge[int(i)].append(int(j))

    ans = len([j for i in hoge[1] if i in hoge for j in hoge[i] if j == n])

    if ans >=1:
        return "POSSIBLE"
    else:
        return "IMPOSSIBLE" 

if __name__ == "__main__":
    n, m = [int(i) for i in input().split()]
    ab_list = [input().split() for i in range(m)]
    print(slove(n, ab_list))
