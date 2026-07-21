import numpy as np
import sys
if __name__ == "__main__":
    N, K = map(int, input().split())
    A = list(map(int, input().rstrip().split(' ')))
    visit = [False]*N
    a_now = 1
    visit[a_now - 1] = True
    step = 0
    for i in range(N):
        a_now = A[a_now - 1]
        step += 1
        #print(a_now)
        if visit[a_now - 1]:
            break
        else:
            visit[a_now - 1] = True
        if step == K:
            #print("K:")
            print(a_now)
            sys.exit()
    
    self_loop = []
    start = a_now
    for i in range(N):
        a_now = A[a_now - 1]
        step += 1
        self_loop.append(a_now)
        if a_now == start:
            break
        if step == K:
            #print("K:")
            print(a_now)
            sys.exit()
    
    ## self_loop が見つかった場合
    #print("a_now:{}".format(a_now))
    #print("step:{}".format(step))
    #print(self_loop)
    n = len(self_loop)
    left = K-step
    left -= (left // n) * n
    #print(step)
    print(self_loop[left - 1])
