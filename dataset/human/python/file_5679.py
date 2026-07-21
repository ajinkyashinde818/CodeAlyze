def ri(): return int(input())
def rli(): return list(map(int, input().split()))
def rls(): return list(input())
def pli(a): return "".join(list(map(str, a)))
def plis(a): return " ".join(list(map(str, a)))


s = input()
ans = 0
s_nox = s.replace('x', '')
if(s_nox != s_nox[::-1]): ans = -1
else:
    need = (len(s_nox)+1) // 2
    s = list(s)
    s_rev = s[::-1]
    si = 0
    srevi = 0
    si_tmp = -1
    srevi_tmp = -1
    for i in range(need):
        si_tmp = 0
        srevi_tmp = 0
        while(s[si] == 'x'):
            si += 1
            si_tmp += 1
        while(s_rev[srevi] == 'x'):
            srevi += 1
            srevi_tmp += 1
        ans += abs(si_tmp - srevi_tmp)
        si += 1
        srevi += 1
print(ans)
