def main():
    s=input()
    q=int(input())
    rot = 0
    A = ''
    B = ''
    for _ in range(q):
        t=input()
        if t=='1':
            rot += 1
        else:
            t = t.split()
            if (int(t[1])+rot)%2==1:
                A += t[2] 
            else:
                B  += t[2]
    if not rot%2:
        print(''.join(A[::-1]+s+B))
    else:
        print(''.join(B[::-1]+s[::-1]+A))        
main()
