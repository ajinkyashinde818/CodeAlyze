import sys

count = 0
N_list = []
M_list = []
for line in sys.stdin:
    line = line.rstrip("\n")
    if count == 0:
        line = line.split(" ")
        N = int(line[0])
        M = int(line[1])
    elif count <= N:
        N_list.append(line)
    else:
        M_list.append(line)
    count+=1
    
    
def judge_match(N_l, M_l):
    slide_count = len(N_l[0]) - len(M_l[0]) + 1
    count = 0
    for j in range(slide_count):
        count = 0
        for i in range(len(N_l)):
            if N_l[i][j:j+len(M_l[0])] == M_l[i]:
                count += 1
                if count == len(M_l):
                    return count
    return count

m_count = 0
for i in range(len(N_list)):
    m_count = judge_match(N_list[i:i+len(M_list)], M_list)
    if m_count == len(M_list):
        print("Yes")
        exit(0)
print("No")
