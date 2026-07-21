import itertools
import math

def all_comb(iterable):
    for i in range(0, len(iterable) + 1):
        comb = itertools.combinations(iterable, i)
        for pair in comb:
            yield(pair)

def min_solve(goal_point, solve, pc_list):
    solve_point = sum([pc[0] * pc[2] + pc[1] for pc in solve])
    solve_num = sum([pc[0] for pc in solve])
    nc_solve = set(pc_list) - set(solve)
    if solve_point >= goal_point:
        return solve_num
    nc_solve_max = max(nc_solve, key=lambda pc:pc[2])
    if solve_point + (nc_solve_max[0] - 1) * nc_solve_max[2]  >= goal_point:
        min_solve = int(math.ceil((goal_point - solve_point) / nc_solve_max[2] + solve_num))
        return min_solve
    else:
        return float('Inf')

if __name__=='__main__':
    D, G = map(int, input().split())
    pc_list = []
    for i in range(D):
        (p, c) = map(int, input().split())
        pc_list.append((p, c, (i + 1) * 100))
    min_num = min([min_solve(G, solve, pc_list) for solve in all_comb(pc_list)])
    print(min_num)
