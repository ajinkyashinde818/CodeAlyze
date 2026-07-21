def main():
    N,K=map(int,input().split())
    A=list(map(int,input().split()))
    pos=set()
    pos.add(0)
    i=0
    traversal=[0]
    start=0
    nodes=[1]
    while(start<K):
        position=A[i]-1
        if position in pos:
            break
        traversal.append(position)
        pos.add(position)
        start+=1
        nodes.append(A[i])
        i=position
    if start==K:
        print(nodes[-1])
    else:
        ind=traversal.index(position)
        interval=len(traversal)-ind
        print(nodes[ind+((K-ind)%interval)])
if __name__=='__main__':
    main()
