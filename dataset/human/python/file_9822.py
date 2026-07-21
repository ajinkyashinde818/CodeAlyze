def d_teleporter():
    N, K = [int(i) for i in input().split()]
    A = [int(i) - 1 for i in input().split()]  # 0-origin

    current_city = 0
    visit_list, visit_dict = [current_city], {current_city: 1}
    for i in range(min(K, N)):  # N 回移動すればループはわかる
        current_city = A[current_city]
        if current_city in visit_dict:  # ループを検出した
            j = visit_list.index(current_city)  # ここからループ
            current_city = visit_list[j + (K - j) % (i - j + 1)]
            break
        else:
            visit_list.append(current_city)
            visit_dict[current_city] = current_city
    return current_city + 1

print(d_teleporter())
