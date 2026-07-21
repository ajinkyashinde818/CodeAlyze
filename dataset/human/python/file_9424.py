if __name__=="__main__":
    N, K = map(int, input().split(' '))
    _town_list = input().split(' ')
    town_list = [int(n) for n in _town_list]

    next_town = town_list[0]
    visited_town = set()
    visited_town.add(1)
    visited_town.add(next_town)
    lst_visited_town = [1]
    lst_visited_town.append(next_town)
    counter = 1

    while True:
        counter += 1
        next_town = town_list[next_town-1]
        if counter == K:
            print(next_town)
            break
        if next_town in visited_town:
            repeated_town_idx = lst_visited_town.index(next_town)
            loop_num = counter - repeated_town_idx
            print(lst_visited_town[(K-repeated_town_idx)%loop_num + repeated_town_idx])
            break
        lst_visited_town.append(next_town)
        visited_town.add(next_town)
