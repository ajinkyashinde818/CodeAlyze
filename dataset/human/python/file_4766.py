import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")

def main():
    def sort_for(s):
        cc = [c for c in s]
        cc.sort()
        s = "".join(cc)
        return s

    def sort_rev(t):
        cc = [c for c in t]
        cc.sort(reverse=True)
        t = "".join(cc)
        return t

    s = input()
    t = input()
    s = sort_for(s)
    t = sort_rev(t)
    st = [s, t]
    st.sort()
    if st[0] == s and s != t:
        print("Yes")
    else:
        print("No")

main()
