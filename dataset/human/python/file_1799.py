def main():
    N, M = map(int, input().split())
    target = list()
    pattern = list()

    for n in range(N):
        l = input()
        target.append(l)

    for m in range(M):
        l = input()
        pattern.append(l)

    find = 0

    for i in range(N):
        for j in range(N):

            if ( i + (M - 1) <= N - 1 ) and (j + (M - 1) <= N - 1)  :
                count = 0

                for k in range(M):
                    for l in range(M):
                        if target[i+k][j+l] != pattern[k][l]:
                            count += 1
                if count == 0:
                    find += 1
                        
    if find:
        print("Yes")
    else:
        print("No")
main()
