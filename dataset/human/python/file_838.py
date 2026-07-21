def read():
    N, R = list(map(int, input().strip().split()))
    return N, R

def solve(N, R):
    inner_rating = 0
    if N >= 10:
        inner_rating = R
    else:
        inner_rating = R + 100 * (10 - N)
    return inner_rating

if __name__ == '__main__':
    inputs = read()
    print("{}".format(solve(*inputs)))
