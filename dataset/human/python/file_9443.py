def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    town = [-1] * N
    town[0] = 0
    next = A[0]
    roop = -1
    until_roop = -1

    for i in range(1, N+1, 1):
        if(i == K):
            print(next)
            return
        if(town[next-1] == -1):
            town[next-1] = i
            next = A[next-1]
        else:
            roop = i - town[next-1]
            until_roop = town[next-1]
            roop_start = next
            break

    mod = (K - until_roop) % roop
    index = roop_start
    while(mod>=0):
        if(mod == 0):
            print(index)
            break
        else:
            index = A[index-1]
            mod -= 1

main()
