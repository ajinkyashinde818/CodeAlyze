d,g=map(int,input().split())
PC=[list(map(int,input().split())) for i in range(d)]
P=list(map(lambda x:x[0],PC))
C=list(map(lambda x:x[1],PC))
ans=10**9
def dfs(cur,target):
  if cur==0:
    return 10**9
  cnt=min(target//(cur*100),P[cur-1]) #P[j]の一部を利用する/全部利用のどちらか小さい方選択
  tmp=(100*cur)*cnt
  if cnt==P[cur-1]:
    tmp+=C[cur-1]
  if tmp<target:
    cnt+=dfs(cur-1,target-tmp)       #減らした値でdfs実行
  return min(cnt,dfs(cur-1,target))
print(dfs(d,g))
