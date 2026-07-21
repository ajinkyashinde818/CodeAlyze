def main():
    N = int(input())
    Ai = [int(a) for a in input().split()]
    Bi = [int(a) for a in input().split()]
    Ci = [int(a) for a in input().split()]
    s = 0
    for i in range(N):
        menu = Ai[i] - 1
        s += Bi[menu - 1]
        if i > 0 :
            if Ai[i] - Ai[i-1] == 1:
                s += Ci[Ai[i-1]-1]
    print(s)
main()
