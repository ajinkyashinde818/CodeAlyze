import collections
MOD = 10 ** 9 + 7
def main():
    N = int(input())
    S = input()

    cc = collections.Counter(S)
    output = 1
    for k in cc.keys():
        output *= (cc[k] + 1)
        output %= MOD
    print(output-1)
    return

if __name__ == '__main__':
    main()
