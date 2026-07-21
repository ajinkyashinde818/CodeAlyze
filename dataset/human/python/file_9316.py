def main():
    _, n_teleport = map(int, input().split())
    towns = [0] + list(map(int, input().split()))

    visited_list = []
    visited_set = set()

    next_town = 1
    while 1:
        if next_town in visited_set:
            loop_start_at = visited_list.index(next_town)
            loop_length = len(visited_list) - loop_start_at
            break

        visited_list.append(next_town)
        visited_set.add(next_town)
        next_town = towns[next_town]

    if n_teleport < loop_start_at:
        end_point = n_teleport
    else:
        end_point = loop_start_at + (n_teleport - loop_start_at) % loop_length

    print(visited_list[end_point])


if __name__ == "__main__":
    main()
