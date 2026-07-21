def main():
    n,k = map(int,input().split())
    dests =[0 for _ in range(n)]
    telepos = list(map(int,input().split()))
    for i,t in enumerate(telepos):
        dests[i] = t-1
    print(solve(dests,k))




def solve(dests,k,here = 0):
    here = 0
    telepo_times = 0
    cycle_start = -1
    cycle_end = -1
    cycle_length = -1
    visited = dict()
    visited2 = []


    #循環検出！同じ町にいつ戻ってくるのか
    while telepo_times < k:
        #print("現在地は",here)
        if here in visited:
            cycle_start = visited[here]
            #print(cycle_start,"でループが始まった")
            cycle_end = telepo_times - 1
            #print(cycle_end,"でループが終わった")
            cycle_length = cycle_end - cycle_start + 1
            #print("サイクルの長さは",cycle_length,"だ")
            break
        #ids[here] = telepo_times

        visited[here] = telepo_times
        visited2.append(here)
        telepo_times += 1
        here = dests[here]
    if cycle_length == -1:
        return here + 1

    cycle_index = (k-cycle_start) % cycle_length
    return visited2[cycle_start + cycle_index] + 1




    #telepo_times = 0
    #while telepo_times < (k - cycle_start)%cycle_length:
    #    telepo_times += 1
    #    here = dests[here]







if __name__ == '__main__':
    main()
