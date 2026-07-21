def main():
    n, k = list(map(int, input().split()))
    a_list = list(map(int, input().split()))
    
    roop_count = []
    for i in range(n):
        roop_count.append(0)
    
    town = 1
    town_candidate = []
    roop_count[0] = 1
    roop_1 = 0
    roop_2 = 0
    count = 0
    for i in range(k):
        town = a_list[town-1]
        roop_count[town-1] += 1
        if roop_count[town-1] == 1:
            roop_1 += 1
        elif roop_count[town-1] == 2:
            roop_2 += 1
            town_candidate.append(town)
        elif roop_count[town-1] == 3:
            break
        count = i
    #print(roop_count)
    
    if count == k-1:
        print(town)
    else:
        town = (k-roop_1) % roop_2 -1
        print(town_candidate[town])

if __name__ == '__main__':
    main()
