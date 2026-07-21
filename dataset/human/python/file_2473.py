D,G = list(map(int,input().split()))
PC = [list(map(int, input().split())) for _ in range(D)]

def all_green(t,s):
    if t == -1:
        return float('inf')
    num = min(PC[t][0],s//(100*(t+1)))
    k = num * 100 * (t+1)
    if num == PC[t][0]:
        k += PC[t][1]
    if k < s:
        num += all_green(t-1,s-k)
    return min(num,all_green(t-1,s))
print(all_green(D-1,G))
