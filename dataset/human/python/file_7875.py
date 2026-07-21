def main():
    N, K, S = map(int, input().split())
    if S == 1:
        print(' '.join(['1'] * K + ['2'] * (N - K)))
    else:
        if S == 10**9:
            print(' '.join([str(S)] * K + ['1'] * max(0, N - K)))
        else:
            if K < N:
                print(' '.join([str(S)] * K + ['1'] + [str(10**9)] * max(0, N - K - 1)))
            else:
                print(' '.join([str(S)] * K))
main()
