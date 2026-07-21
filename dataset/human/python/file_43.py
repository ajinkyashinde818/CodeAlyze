def main():
    r, g, b, n = map(int, input().split())

    count = 0

    for i in range(3001):
        for j in range(3001):
            v = (i*r) + (j*g) 
            if n >= v and (n-v)%b == 0: 
                count += 1



    print(count)
                

if __name__=='__main__':
    main()
