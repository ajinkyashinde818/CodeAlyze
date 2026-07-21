def sub_count(S,N,M):
    S_dict,S_set = {},set()

    for i in range(N):
        if S[i] not in S_set:
            S_set.add(S[i])
            S_dict[S[i]] = 1
        else:
            S_dict[S[i]] += 1

    output = 1
    for s in S_set:
        output *= (S_dict[s]+1)
        output %= M
    output -= 1
    return output

def main():
    N = int(input())
    S = input()
    M = 10**9+7

    ans = sub_count(S,N,M)
    print(ans)

if __name__ == "__main__":
    main()
