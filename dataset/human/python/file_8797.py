k, n = map(int, input().split())
home_positions = list(map(int, input().split()))


def max_distance_homes(homes):
    max_distance = 0
    for i in range(len(homes) - 1):
        distance = homes[i + 1] - homes[i]
        if max_distance < distance:
            max_distance = distance
    distance = k + homes[0] - homes[-1]
    if max_distance < distance:
        max_distance = distance
    return max_distance


print(k - max_distance_homes(home_positions))
