import sys
sys.setrecursionlimit(10000)
D, G = list(map(int, input().split(' ')))
left = {}
bonus = {}
for i in range(1, D+1):
    left[i], bonus[i] = list(map(int, input().split(' ')))
 
big = 9999999
 
probably_ans = big
memo = {}
def hogehoge(depth, index, pt, left, bonus, probably_ans):
    key = (depth, index, pt, str(left))
    if key in memo:
        return memo[key]
    if pt >= G:
        return depth
    if depth >= probably_ans or index > D:  # 遅いかも
        return big
    
    # 一つも引かない
    probably_ans = min(probably_ans, hogehoge(depth, index + 1, pt, left, bonus, probably_ans))
    
    # 全部引いて index reset
    for k in range(0, D - index + 1):
        if left[index + k]:
            temp = left[index + k]
            left[index + k] = 0
            probably_ans = min(probably_ans, hogehoge(depth+temp, 1, pt + (index + k) * 100 * temp + bonus[index + k], left, bonus, probably_ans))
            left[index + k] = temp

    # 歯抜け状態から行けそうならクリア
    if left[index]:
        if pt + index * 100 * left[index] + bonus[index] >= G:
            for i in range(1, left[index] + 1):
                left[index] = left[index] - i
                new_pt = pt + index * 100 * i + bonus[index] * (left[index] == 0)
                if (new_pt >= G):
                    probably_ans = min(probably_ans, hogehoge(depth+i, index+1, new_pt, left, bonus, probably_ans))
                left[index] = left[index] + i
    memo[key] = probably_ans
    return probably_ans
    
print(hogehoge(0, 1, 0, left, bonus, probably_ans))
