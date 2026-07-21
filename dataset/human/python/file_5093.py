import bisect
def main():
    n,m=map(int,input().split(' '))
    mid=[]
    goal=[]
    for i in range(m):
        a,b=map(int,input().split(' '))
        if a==1:
            mid.append(b)
        if b==n:
            goal.append(a)
    mid = sorted(mid)
    for g in goal:
        i=bisect.bisect_left(mid,g)
        j=bisect.bisect_right(mid,g)
        if i != j:
            print('POSSIBLE')
            exit()
    print('IMPOSSIBLE')



if __name__ == '__main__':
    main()
