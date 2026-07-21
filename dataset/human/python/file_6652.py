import sys
input = sys.stdin.readline

def main():
    
    s = str(input().rstrip())
    q =int(input())
    ten = 0
    r = []
    l = []
    la = l.append
    ra =r.append
    for _ in range(q):
        ls = tuple(map(str, sys.stdin.readline().split()))
        if len(ls)==1:
            ten +=1
        else:
            if ls[1] =='1':
                if ten%2 ==0:
                    la(ls[2])
                else:
                    ra(ls[2])
            else:
                if ten%2 ==1:
                    la(ls[2])
                else:
                    ra(ls[2])
    s = ''.join(reversed(l))+s+''.join(r)
    if ten%2 ==1:
        s = s[::-1]
    print(s)
if __name__ == '__main__':
    main()
