def main():
    import sys

    def input(): return sys.stdin.readline().rstrip()
    
    n, m = map(int, input().split())
    a = [input() for _ in range(n)]
    b = [input() for _ in range(m)]
    for i in range(n-m+1):
        for j in range(n-m+1):
            flag = False
            for k in range(m):
                for l in range(m):
                    if a[i+k][j+l] != b[k][l]:
                        flag = True
                        break
                if flag:
                    break
            if not flag:
                break
        if not flag:
            break
    if not flag:
        print('Yes')
    else:
        print('No')
                
    

            

    
if __name__ == '__main__':
    main()
