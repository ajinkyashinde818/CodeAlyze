import itertools
def slove(n, a):
    total = sum(a)
    ans = min(map(lambda x: abs(total - x*2), itertools.accumulate(a[:-1])))
    return ans

if __name__ == "__main__":
    n = int(input())
    a_list = [int(i) for i in input().split()]
    print(slove(n, a_list))
