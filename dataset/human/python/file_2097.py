import collections

count = collections.Counter
mod = 1000000007

def main():
    N = int(input())
    S = input()

    valuelist = list(count(S).values())
    ans = 1
    for v in valuelist:
        ans = (ans * (v + 1))%mod

    ans -= 1

    print(ans)


if __name__ == "__main__":
    main()
