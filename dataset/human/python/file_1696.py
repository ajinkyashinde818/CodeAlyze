def main():
    n, m = (int(i) for i in input().split())
    a = [input() for i in range(n)]
    b = [input() for i in range(m)]
    
    equal_flag = False
    k = 0
    for i in range(n):
        for j in range(n-m+1):
            if a[i][j:j+m] == b[k]:
                plus = 1
                while k+plus != m:
                    if i+plus >= n or a[i+plus][j:j+m] != b[k+plus]:
                        break
                    plus += 1
                else:
                    equal_flag = True
        if equal_flag:
            print("Yes")
            break
    else:
        print("No")
 
if __name__ == '__main__':
    main()
