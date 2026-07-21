d , g = map(int, input().split())
p = [0] + [list(map(int, input().split())) for _ in range(d)]

def f(i,s):
    if i == 0: return 10**9
    cnt = min(s//(100 * i), p[i][0])
    score = 100*i*cnt
    if (cnt==p[i][0]):
        score += p[i][1]
    
    if (s > score):
        cnt += f(i-1,s-score)
    
    return min(cnt, f(i-1,s))

def main():
    print(f(d,g))
main()
