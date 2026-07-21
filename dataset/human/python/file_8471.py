def get_maximam_distance(k, positions):
    distance_tmp = 0
    for i in range(1, len(positions)):
        distance_tmp = max(distance_tmp, positions[i] - positions[i - 1])
    return max(distance_tmp, positions[0] + k - positions[len(positions) - 1])

params_0 = input().split()
params_1 = input().split()
param_K = int(params_0[0])
positions = list(map(lambda x: int(x), params_1))
print(param_K - get_maximam_distance(param_K, positions))
