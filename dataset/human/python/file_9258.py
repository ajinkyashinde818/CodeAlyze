s=list(input())
s=s[::-1]
start=0
def find(s,start):
    if len(s)-start>=5 and (s[start:start+5]==list("maerd") or s[start:start+5]==list("esare")):
        start=start+5
        return(start,0)#左がstart,右がまだ処理続行
    elif len(s)-start>=6 and s[start:start+6]==list("resare"):
        start=start+6
        return(start,0)
    elif len(s)-start>=7 and s[start:start+7]==list("remaerd"):
        start=start+7
        return(start,0)
    elif len(s)-start==0:
        return(start,1)#1はぴったり終了
    else:
        return(start,2)#2は満たさないで終了
shori=0
while shori==0:
    (start,shori)=find(s,start)
if shori==1:
    print("YES")
else:
    print("NO")
