import numpy as np

def main():
    n, k = map(int, input().split())
    a = list(map(lambda x: int(x)-1, input().split()))
    foot = [0]
    is_loop = False
    ed = np.zeros([n], dtype=int)
    ed[0] = 1

    for i in range(1,k):
        go = a[foot[-1]]
        foot.append(go)
        if ed[go] == 1:
            st_i = foot.index(foot[-1])
            lo_size = len(foot)-1 - st_i

            k -= st_i
            k %= lo_size
            
            print(foot[st_i+k]+1)
            is_loop = True
            break
        ed[go] = 1
    
    if not is_loop:
        print(a[foot[-1]]+1)


if __name__ == '__main__':
    main()
