import sys
def IL(): return map(int,sys.stdin.readline().rstrip().split())

def Main():
    k,n = IL()
    a = list(IL())
    a.sort()
    m = 0
    for i in range(n):
        if i<n-1:
            m = max(m,a[i+1]-a[i])
        else:
            m = max(m,k-a[i]+a[0])
    print(k-m)
    return

if __name__=='__main__':
    Main()
