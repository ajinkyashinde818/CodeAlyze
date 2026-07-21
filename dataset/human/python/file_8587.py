def main():
    k, n = (int(i) for i in input().split())
    st = [int(i) for i in input().split()]

    st = sorted(st)
    st.append(st[0] + k)

    diffs = [st[i+1] - st[i] for i in range(n)]

    print(k - max(diffs))

main()
