def main():
    N, K = map(int, input().split())
    A = [a-1 for a in map(int, input().split())]    # 0-indexed に変換
    B = [None]*N    # 何ステップ目に到達したかを記録。Noneなら未到達を表す
    now = 0         # 現在地
    step = 0        # ステップ数
    B[now] = 0      # 開始地点は、0ステップ目に到達済みとする
    while K:
        now = A[now]    # 現在地を更新 
        step += 1
        K -= 1
        if B[now] is not None:  # ループを検出したら...
            K %= (step - B[now])      # Kからループ長さを引けるだけ引く
        else:
            B[now] = step  # 到達したステップ数を記録
    print(now+1)    # 1-indexed に再変換
 
main()
