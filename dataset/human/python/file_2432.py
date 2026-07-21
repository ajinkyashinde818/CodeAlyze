from itertools import permutations, product
from math import ceil, floor

D, G = [int(elem) for elem in input().split(' ')]
point_info_list = [[int(elem) for elem in input().split()] for _ in range(D)]
assert len(point_info_list) == D
assert len(point_info_list[0]) == 2

# time complexity: O(D!)
""" min_num = float('inf')
for perm in permutations(range(D)):
    current_point = 0
    current_num = 0
    for point in perm:
        if (G - current_point) - (point + 1) * 100 * point_info_list[point][0] <= 0:
            current_num += ceil((G - current_point) / ((point + 1) * 100))
            break
        elif (G - current_point) - (point + 1) * 100 * point_info_list[point][0] - point_info_list[point][1] <= 0:
            current_num += point_info_list[point][0]
            break
        else:
            current_point += (point + 1) * 100 * point_info_list[point][0] + point_info_list[point][1]
            current_num += point_info_list[point][0]
    min_num = min(current_num, min_num)

print(min_num)
 """

# time complexity: O(D2^D)
min_num = float('inf')
for mask in product([False, True], repeat=D):
    chosen_indices = [i for i, chosen in enumerate(mask) if chosen]
    current_point = 0
    current_num_solved = 0
    for chosen_index in chosen_indices:
        point = (chosen_index + 1) * 100
        num_problems = point_info_list[chosen_index][0]
        bonus = point_info_list[chosen_index][1]
        current_point += point * num_problems + bonus
        current_num_solved += num_problems

    if current_point >= G:
        min_num = min(min_num, current_num_solved)
    else:
        chosen_indices = set(chosen_indices)
        max_index = max([i for i in range(D) if i not in chosen_indices])
        point = (max_index + 1) * 100
        num_problems = point_info_list[max_index][0]
        if current_point + point * num_problems < G:
            continue
        else:
            current_num_solved += ceil((G - current_point) / point)
            min_num = min(min_num, current_num_solved)

print(min_num)
