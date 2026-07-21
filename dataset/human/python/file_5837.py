def buffet(n, ali, bli, cli):

    ans = 0
    count = 10**5

    for i in range(n):
        ans += bli[ali[i]-1]

        if ali[i] == count+1:
            ans += cli[count-1]
        count = ali[i]
    return ans

def main():
    n = int(input())
    ali = list(map(int, input().split()))
    bli = list(map(int, input().split()))
    cli = list(map(int, input().split()))
    print(buffet(n, ali, bli, cli))

if __name__ == '__main__':
    main()
