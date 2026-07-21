def hinan():
    ans ,houi ,vector = [] ,[[0 ,1] ,[-1 ,0] ,[0 ,-1] ,[1 ,0] ,[0 ,1] ,[-1 , 0] ,[1 ,0]] ,["E" ,"N" ,"W" ,"S"]
    while True:
        n = raw_input().split(" ")
        if n == ["0" ,"0"]:
            for an in ans:
                print an
            break
        else:
            xs =[[] ,[] ,[]]
            for i in range(int(n[1])):
                n = raw_input()
                xs = [xs[l] + [[[i ,j] for j in range(len(n)) if n[j] != "#"] ,[[[i ,j] ,houi[vector.index(n[j])]] for j in range(len(n)) if n[j] in vector] ,[[i ,j] for j in range(len(n)) if n[j] == "X"]][l] for l in range(3)]
            for time in range(181):
                if len(xs[1]) == 0:
                    ans.append(time)
                    break
                else:
                    for i in xs[1]:
                        where = [l[0] for l in xs[1]]
                        if len([k for k in [[i[0][l] + houi[houi.index(i[1]) - 1 + j][l] for l in range(2)] for j in range(4)] if k in xs[0] and not k in where]) > 0:
                            i[1] = [[k for k in [[i[0][l] + houi[houi.index(i[1]) - 1 + j][l] for l in range(2)] for j in range(4)] if k in xs[0] and not k in where][0][s] - i[0][s] for s in range(2)]
                    go_point = [[i[0][l] + i[1][l] for l in range(2)] for i in xs[1]]
                    for i in range(len(go_point)):
                        if go_point[i] in where or not go_point[i] in xs[0]:
                            go_point[i] = xs[1][i][0]
                        else:
                            if go_point.count(go_point[i]) > 1:
                                for j in range(4):
                                    if xs[1][i] == [[go_point[i][l] + houi[j][l] for l in range(2)] ,houi[j + 2]]:
                                        break
                                    elif [[go_point[i][l] + houi[j][l] for l in range(2)] ,houi[j + 2]] in xs[1]:
                                        go_point[i] = xs[1][i][0]
                                        break
                    else:
                        xs[1] = [k for k in [[go_point[i] ,xs[1][i][1]] for i in range(len(xs[1]))] if not k[0] in xs[2]]
            else:
                ans.append("NA")
hinan()
