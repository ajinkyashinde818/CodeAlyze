from sys import stdin

[D, G] = [int(x) for x in stdin.readline().rstrip().split()]
data = [[int(x) for x in stdin.readline().rstrip().split()] for _ in range(D)]

def calculate_score(arr): #arrは100i点の問題を解いた数の配列, 長さはD
    tot_score = 0
    for i in range(len(arr)):
        num = arr[i]
        tot_score += num * 100*(i+1)
        if num == data[i][0]:
            tot_score += data[i][1]
    return tot_score

def func1(arr,G): #arrは長さDの配列で、それぞれi点問題のボーナスを得るかどうか
    #arrだけのボーナスを得たときに、総合スコアをG点にするための問題数は容易に求められる

    problem_num = 0
    tot_score = 0
    for i in range(len(arr)):
        if arr[i] == 1:
            tot_score += data[i][1]
            tot_score += data[i][0]*100*(1+i)
            problem_num += data[i][0]
    
    if tot_score>=G:
        return problem_num

    for i in range(len(arr)):
        if arr[len(arr)-i-1]==0:
            for j in range(data[len(arr)-i-1][0]-1):
                tot_score += 100*(len(arr)-i)
                problem_num+=1
                if tot_score>=G:
                    return problem_num
    
    return 100000

min_problem = 10000
for i in range(2**D):
    i_bin = bin(i)
    i_bin_arr = []
    for j in range(D-len(i_bin[2:])):
        i_bin_arr.append(0)

    for j in range(len(i_bin[2:])):
        i_bin_arr.append(int(i_bin[2+j]))

    problem_num = func1(i_bin_arr,G)
    if problem_num<min_problem:
        min_problem=problem_num

print(min_problem)
