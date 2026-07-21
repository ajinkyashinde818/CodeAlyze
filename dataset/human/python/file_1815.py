n, m = map(int, input().split())
a = [input() for _ in range(n)]
b = [input() for _ in range(m)]

def main():

    for i in range(n-m+1):
        for j in range(n-m+1):
            if match(i, j):
                print("Yes")
                exit()
    
    print("No")

def match(x, y):
    for i in range(m):
        for j in range(m):
            if (a[x+i][y+j] != b[i][j]):
                return False

    return True

if __name__ == "__main__":
    main()
