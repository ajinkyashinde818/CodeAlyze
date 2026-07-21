def solve(problem,l):
    re = []
    for i in range(len(l)):
        if i == problem:
            re.append(l[i] + 1)
        else:
            re.append(l[i])
    return re



D,G = (int(i) for i in input().split())  
p = []
c = []
for _ in range(D):
    p_t,c_t =  (int(i) for i in input().split())
    p.append(p_t)
    c.append(c_t)

state = []
for _ in range(10100):
    state.append([0] * (D + 1))

i = 0
for j in range(D):
    point = state[i][-1]
    if p[j] > state[i][j]:
        point += 100 * (j + 1) * (p[j] - state[i][j])
        point += c[j]

        if state[i + (p[j] - state[i][j])][-1] < point:
            new_state = state[i] 
            for _ in range(p[j] - state[i][j]):
                new_state = solve(j,new_state)
            state[i + (p[j] - state[i][j])] = new_state
            state[i + (p[j] - state[i][j])][-1] = point
i += 1
while(True):
     #最後だけ取れる得点
    problem = 0
    for j in range(D):
        point = state[i-1][-1]
        if p[j] > state[i-1][j]:
            point += 100 * (j + 1)
            if p[j] - state[i-1][j] == 1:
                point += c[j]

        if state[i][-1] < point:
            state[i] = solve(j,state[i-1])
            state[i][-1] = point
    #print(state[0:10])
    for j in range(D):
        point = state[i][-1]
        if p[j] > state[i][j]:
            point += 100 * (j + 1) * (p[j] - state[i][j])
            point += c[j]

            if state[i + (p[j] - state[i][j])][-1] < point:
                new_state = state[i] 
                for _ in range(p[j] - state[i][j]):
                    new_state = solve(j,new_state)
                state[i + (p[j] - state[i][j])] = new_state
                state[i + (p[j] - state[i][j])][-1] = point

    #print(state[0:10])
    if state[i][-1] >= G:
        #print(state)
        print(i)
        break
    i += 1
