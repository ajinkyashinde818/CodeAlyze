import itertools

def solve(D, G, problems):
    bit_list = list(itertools.product([0, 1], repeat=D))
    
    result_count = 10 ** 8
    for pattern in bit_list:
        score = 0 # スコアの合計
        count = 0  # 解いた問題数
        for i in range(D):
            if pattern[i] == 1: # ビット値が１の難易度の問題は全て解く
                score += problems[i][0] * (i+1) * 100 + problems[i][1]  # 問題のスコア + ボーナス点
                count += problems[i][0]
            
            else:
                max_score_problem = i
    
        # 合計スコアが足りない場合，もっともスコアの高い未着手の問題を必要な分だけ解く
        if score < G:
            for i in range(problems[max_score_problem][0]):
                count += 1
                score += (max_score_problem + 1) * 100
                if score >= G:
                    break
        
        if score >= G:
            result_count = min(result_count, count)
            
    print(result_count)
    

if __name__ == '__main__':
    D, G = map(int, input().split())
    problems = [list(map(int, input().split())) for _ in range(D)]
    solve(D, G, problems)
