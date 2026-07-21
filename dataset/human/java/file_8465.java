import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=Integer.parseInt(sc.next());
        int k=Integer.parseInt(sc.next());
        int l=Integer.parseInt(sc.next());
        UnionFindTree roads=new UnionFindTree(n);
        for(int i=0;i<k;i++){
            roads.union(Integer.parseInt(sc.next())-1,Integer.parseInt(sc.next())-1);
        }
        UnionFindTree trains=new UnionFindTree(n);
        for(int i=0;i<l;i++){
            trains.union(Integer.parseInt(sc.next())-1,Integer.parseInt(sc.next())-1);
        }
        HashMap<Pair,Integer> map=new HashMap<>();
        for(int i=0;i<n;i++){
            Pair p=new Pair(roads.find(i),trains.find(i));
            if (map.containsKey(p)){
                map.put(p,map.get(p)+1);
            }else{
                map.put(p,1);
            }
        }
        StringBuilder sb=new StringBuilder();
        for (int i=0;i<n;i++){
            if(i!=0){
                sb.append(" ");
            }
            Pair p=new Pair(roads.find(i),trains.find(i));
            sb.append(map.get(p));
        }
        System.out.println(sb);
    }
}

class Pair{
    int x;
    int y;
    public Pair(int x,int y){
        this.x=x;
        this.y=y;
    }
    @Override
    public int hashCode(){
        return Objects.hash(x,y);
    }
    @Override
    public boolean equals(Object o){
        if(o==this){
            return true;
        }
        if(!(o instanceof Pair)){
            return false;
        }
        Pair p=(Pair) o;
            return p.x==x && p.y==y;
    }
}

class UnionFindTree{
    int[] par;
    int[] rank;
    public UnionFindTree(int size){
        this.par=new int[size];
        this.rank=new int[size];
        for (int i=0;i<size;i++){
            makeSet(i);
        }
    }
    public void makeSet(int i){
        par[i]=i;
        rank[i]=0;
    }
    public void union(int x,int y){
        int xRoot=find(x);
        int yRoot=find(y);
        if(rank[xRoot]>rank[yRoot]){
            par[yRoot]=xRoot; 
        }else if(rank[xRoot]<rank[yRoot]){
            par[xRoot]=yRoot;
        }else if(xRoot!=yRoot){
            par[yRoot]=xRoot;
            rank[xRoot]++;
        }
    }
    public int find(int i){
        if (i!=par[i]){
            par[i]=find(par[i]);
        }
        return par[i];
    }
    public boolean same(int x,int y){
        return find(x)==find(y);
    }
}
