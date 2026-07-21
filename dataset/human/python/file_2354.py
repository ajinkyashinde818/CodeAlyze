D, G = map(int, input().split())
pc = [list(map(int, input().split())) for _ in range(D)]

def dfs(question_num, rquired_point):
    if question_num < 0:
        return 10 ** 9

    point = (question_num+1) * 100
    ans_num = min(rquired_point // point, pc[question_num][0])
    score = ans_num * point

    if ans_num == pc[question_num][0]:
        score += pc[question_num][1]

    if rquired_point > score:
        ans_num += dfs(question_num-1, rquired_point-score)
    
    return min(ans_num, dfs(question_num-1, rquired_point))

print(dfs(D-1, G))
