from sys import stdin,stdout

if __name__=="__main__":

    n=int(stdin.readline());

    a=[int(x) for x in stdin.readline().split()]
    b=[int(x) for x in stdin.readline().split()]
    c=[int(x) for x in stdin.readline().split()]

    sm=sum(b)

    for i in range(1,n):
        if a[i]-1==a[i-1]:
            sm+=c[a[i-1]-1]
    stdout.write(str(sm)+"\n")
