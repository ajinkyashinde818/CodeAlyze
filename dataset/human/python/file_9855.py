if __name__ == '__main__':

    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    root = [] # 訪れた頂点をメモ
    already = [-1] * (n+1) # rootのindexのメモ　と　すでに訪れたか

    c = 1# 周期
    l = 0# 例外部分のながさ
    """
    周期は　書き換えようとした時の　書き換えたかった数 - すでに書いてある数
    """

    v = 1#頂点は1 ここから遷移
    while(already[v] == -1): # すでに書いてあれば訪れている。かつ周期の起点となる場所
        already[v] = len(root) #訪れたら何回目かを記述
        root.append(v)
        v = a[v-1]

    c = len(root) - already[v]
    l = already[v]

    if k < l:#例外部分のながさ
        ans = root[k]
    else:# 周期にいるなら
        k -= l
        ans = root[k%c+l]

    print(ans)
