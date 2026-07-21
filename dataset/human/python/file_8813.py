k, n = map(int, input().split())
position_list = list(map(int, input().split())) 

def get_dis(distance_list):
    longest = 0
    sum = 0
    for num in distance_list:
        sum += num
        if num > longest:
            longest = num
    return (sum-longest)

def cover(k, n, position_list):
    distance_list = []
    for i in range(len(position_list)-1):
        distance = position_list[i+1] - position_list[i]
        distance_list.append(distance)
    # 最初と最後の距離
    distance_list.append(position_list[0]+k-position_list[-1])
    ans = get_dis(distance_list)
    return ans

print(cover(k, n, position_list))
