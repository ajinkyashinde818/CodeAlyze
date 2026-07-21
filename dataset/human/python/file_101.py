from sys import stdin

def main():
    point = 0
    r,g,b,n = [int(x) for x in stdin.readline().rstrip().split()]
    for i in range(n//r+1):
        for j in range((n-r*i)//g+1):
            if n-r*i-g*j >= 0:
                if (n-r*i-g*j)%b == 0:
                    point += 1
    print(point)

if __name__ == "__main__":
    main()
