def parial_solve(G, pb_set):
    if(G >= pb_set[3]):
        return -1
    for num in range(pb_set[1]):
        score = pb_set[0] * num
        if(score >= G):
            return num
    return -1       

def main():
    import heapq
    from itertools import combinations

    D, G = map(int, input().split())
    pc = []
    answer_list = []
    for i in range(1, D+1, 1):
        prob_num, bonus_score = map(int, input().split())
        # List of problem set:(score for single prob, num of prob, bonus score)
        total_score = 100 * i * prob_num + bonus_score
        pc.append((i*100, prob_num, bonus_score, total_score))

    for i in range(D+1):
        for comb in combinations(range(D), i):
            score = 0
            answer_num = 0
            for p_index in comb:
                prob = pc[p_index]
                score += prob[3]
                answer_num += prob[1]
            if(score >= G):
                # Not neeed to use partial solve
                answer_list.append((answer_num, comb))
            else:
                # Partial solve for 
                max_prob_index = max(set(range(D)) - set(comb))
                pb_set = pc[max_prob_index]
                partial_solve_num = parial_solve(G - score, pb_set)
                if(partial_solve_num == -1):
                    continue
                else:
                    answer_list.append((answer_num+partial_solve_num, comb, max_prob_index))
    import heapq
    heapq.heapify(answer_list)
    print(heapq.heappop(answer_list)[0])

main()
