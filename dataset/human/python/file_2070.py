def main():
    N = int(input())
    S = input()
    ans = {}
    for s in range(ord('a'),ord('z')+1):
        ans[chr(s)] = 0
    for s in S:
        if not ans[s]:
            ans[s] = 1
        else:
            ans[s] += 1
    res = 1
    for _, v in ans.items():
        res *= v+1
    return res - 1


if __name__ == '__main__':
    print(main() % (10**9+7))
