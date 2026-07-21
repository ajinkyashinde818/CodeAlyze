def main():
    from sys import stdin
    n,k = map(int,stdin.readline().rstrip().split())
    As = list(map(int,stdin.readline().rstrip().split()))
    As = [0]+As
    g = set({1})
    l = [0,1]
    now = 1
    i = 0
    while True:
        i+=1
        now = As[now]
        if now in g:
            j = l.index(now)
            print(l[j+(k-i)%(i+1-j)])
            break
            
        else:
            g.add(now)
            l.append(now)
        
        if i == k:
            print(now)
            break
main()
