N, M = map(int, input().split())
A_list = [input() for _ in range(N)]
B_list = [input() for _ in range(M)]

b_str = ''.join(B_list)
def judge_same(str1, str2):
    return str1 == str2
judge = False
finish = False
for i in range(N - M + 1):
    for j in range(N - M + 1):
        a_str = ''.join([A_list[i + x][j:(j+M)] for x in range(M)])
        judge = judge_same(a_str, b_str)
        if judge:
            finish = True
            break
    if finish:
        break
if judge:
    print('Yes')
else:
    print('No')
