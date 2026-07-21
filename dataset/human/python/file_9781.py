ii = lambda : int(input())
mi = lambda : map(int,input().split())
li = lambda : list(map(int,input().split()))

def main():
    n,k = mi()
    a =li()

    fp = [0] * n

    nxt = 0
    for i in range(1,n+10):
        
        idx = a[nxt]-1
        # print('idx',idx)
        if i == k:
            print(idx+1)
            return
        elif fp[idx] > 0:
            rs = fp[idx]
            re = i
            break
        
        else:
            fp[idx] = i
            nxt = idx

    roop_count = re - rs

    modd = (k - rs)%roop_count
    for i in range(modd):
        idx = a[idx]-1
    print(idx+1)
    return

if __name__ == "__main__":
    main()
