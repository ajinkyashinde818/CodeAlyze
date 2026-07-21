def main():
    N, K = map(int, input().split())
    A    = [int(i)-1 for i in input().split()]

    visited_town = []
    current_town = 0
    loop_flg     = False
    visited_town.append(current_town)
    set_visted_town = set(visited_town)
    for i in range(K):
        current_town = A[current_town]
        if current_town in set_visted_town:
            visited_town.append(current_town)
            loop_flg = True
            break
        visited_town.append(current_town)
        set_visted_town.add(current_town)


    if loop_flg:
        loop_start = visited_town.index(current_town)
        loop_end   = len(visited_town) - 1
        loop_length = loop_end - loop_start
        last_index = (K-loop_start)%loop_length
        current_town = visited_town[loop_start+last_index]

    print(current_town+1)


if __name__ == '__main__':
    main()
