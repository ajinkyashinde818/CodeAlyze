import sys
import math
sys.setrecursionlimit(1000000) # 再帰上限を増やす

def main():
    input = sys.stdin.readline  # 文字列に対してinputした場合は、rstripするのを忘れずに！
    D, G = map(int, input().rstrip().split())
    problem_list = []
    for i in range(1, D+1):
        p, c = map(int, input().rstrip().split())
        problem_list.append((p, c + (i * 100 * p), i * 100))

    min_problems = 10**9
    for bit in range(1 << D):
        problem_num = 0
        total_score = 0
        unsolved_problems = None

        for i in range(D):
            if bit & (1 << i):
                # ボーナスポイントを取得
                problem_num += problem_list[i][0]
                total_score += problem_list[i][1]
                if problem_num >= min_problems:
                    break
            else:
                # ボーナスポイントを取得しない
                unsolved_problems = problem_list[i]

        if problem_num >= min_problems:
            continue

        if G <= total_score:
            min_problems = min(min_problems, problem_num)
        else:
            diff = G - total_score
            num, _, score = unsolved_problems
            needed_num = math.ceil(diff / score)
            if num > needed_num:
                problem_num += needed_num
                total_score += needed_num * score
                min_problems = min(min_problems, problem_num)
    print(min_problems)

if __name__ == '__main__':
    main()
