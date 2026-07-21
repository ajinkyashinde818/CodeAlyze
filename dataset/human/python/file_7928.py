from itertools import permutations

S=input()
cand=["".join(t) for t in list(permutations(["a","b","c"],3))] # "a","b","c"を並び替えてできる文字列の候補

if S in cand: # ありえる場合
    print("Yes")
else: # ありえない場合
    print("No")
