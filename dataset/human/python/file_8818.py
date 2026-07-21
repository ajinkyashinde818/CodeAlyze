K, N = list(map(int, input().split()))
lst_A = list(map(int, input().split())) 

def main(K, N, lst_A):

    diff_dis = [lst_A[i+1] - lst_A[i] for i in range(N-1)]
    diff_dis.append(K-lst_A[-1] + lst_A[0])

    sum_diff = sum(diff_dis)
    answer = sum(diff_dis)

    for diff in diff_dis:
        _answer = sum_diff - diff
        answer  = min(answer, _answer)

    return answer

if __name__ == "__main__":

    answer = main(K, N, lst_A)
    print(answer)
