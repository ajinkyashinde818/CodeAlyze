import numpy as np

def check_num_of_remaining_teleport(num_of_teleport, i):
    if num_of_teleport == 0:
        print(i)
        exit()

num_of_town, num_of_teleport = map(int, input().split())
town = np.array(list(map(int, input().split())))

# 香り高い町の探索
i = 1
# テレポートの移動ルールに合わせて1始まりにする
fragranttown_index = 1
fragrants = [0] * num_of_town
fragrants[0] = 1
for _ in range(num_of_town):
    i = town[i - 1]
    num_of_teleport = num_of_teleport - 1

    # 移動回数が終了した場合
    check_num_of_remaining_teleport(num_of_teleport, i)

    # すでに通った町か
    if fragrants[i - 1] != 1:
        fragrants[i - 1] = 1
    else:
        fragranttown_index = i
        break

# 香り高い町への再訪までの回数探索
# 再訪までの回数
revisit = 0
j = fragranttown_index
for _ in range(num_of_town):
    j = town[j - 1]
    revisit = revisit + 1
    num_of_teleport = num_of_teleport - 1

    # 移動回数が終了した場合
    check_num_of_remaining_teleport(num_of_teleport, j)

    # テレポート先が香り高い町なら
    if fragranttown_index == j:
        break

# 香り高い町からの最終移動
num_of_last_teleport = num_of_teleport % revisit
k = fragranttown_index
# rangeの中は一時変数にした方が高速
for _ in range(num_of_last_teleport):
    k = town[k - 1]
    
print(k)
