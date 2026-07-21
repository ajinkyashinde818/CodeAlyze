d,g=map(int,input().split())
l=[0]+[list(map(int,input().split())) for i in range(d)]

def fnc(a,b):#点の大きいものから解いていく
    if a==0:#全部試したらおわり
        return 10**9
    s=min(l[a][0],b//(a*100))#全部か部分か
    t=100*a*s#基本スコア
    if s==l[a][0]:
        t+=l[a][1]#ボーナス
    if t<b:#達してないなら
        s+=fnc(a-1,b-t)#次の問題
    return(min(s,fnc(a-1,b)))#a-1問目から解く
print(fnc(d,g))
