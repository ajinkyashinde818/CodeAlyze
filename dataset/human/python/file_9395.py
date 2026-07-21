def main():

    N_machi, K_teleport = map(int, input().split())
    to_teleport = list(map(int, input().split()))

    visited_city = [1]
    order = [-1 for i in range(N_machi + 1)]
    order[1] = 0
    next_city = 1
    
    for i in range(N_machi):
        next_city = to_teleport[next_city - 1]
        tmp = order[next_city]
        
        if (tmp == -1):
            visited_city.append(next_city)
            order[next_city] = i + 1
        else:
            break
    
    first = order[next_city]
    len_loop = len(visited_city) - first
    
    if (K_teleport < first):
        ans = visited_city[K_teleport]
    else:
        mod = (K_teleport - first) % len_loop
        ans = visited_city[first + mod]
    
    print(ans)
        

if __name__ == '__main__':
    main()
