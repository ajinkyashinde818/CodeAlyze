'''
AtCoder Grand Contest 030
A - Poisonous Cookies
'''


def main():
    a, b, c = map(int, input().split())

    '''
    A + B + 1 ≥ C ならすべての毒入りの
    クッキーを食べることができるので B + C。
    そうでないなら答えはB + (A + B + 1) 。
    ※「+1」は最後にCを食べるので
    '''
    print(b + min(c, a + b + 1))


if __name__ == "__main__":
    main()
