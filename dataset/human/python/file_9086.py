import itertools
s=input()

li=list(itertools.permutations(["dream","erase","dreamer","eraser"]))

for i in li:
    t=s
    for j in range(4):
        t=t.replace(i[j],"")
    else:
        if t=="":
            print("YES")
            exit()

print("NO")
