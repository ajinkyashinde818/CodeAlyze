def main():
    s = input()
    q = int(input())
    l,r = '',''
    rev = 0
    for i in range(q):
        Q = input().split()
        if Q[0]=="1":
            rev = (rev+1)%2
        else:
            if Q[1]=='1':
                if rev==0:
                    l = Q[2]+l
                else:
                    r = r+Q[2]
            else:
                if rev==0:
                    r = r+Q[2]
                else:
                    l = Q[2]+l
    s = l+s+r
    if rev==0:
        print(s)
    else:
        print(s[::-1])

if __name__ == "__main__":
    main()
