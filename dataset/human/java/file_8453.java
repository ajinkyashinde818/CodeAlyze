import java.io.*;
import java.util.*;
import static java.lang.System.out;

public class Main{
    static MyReader in = new MyReader();

    public static void main(String[] args){
        final int N, K, L; {int[] a = in.ii(); N = a[0]; K = a[1]; L = a[2];}
        
        UnionFind road = new UnionFind(N+1);
        for(int i = 0; i < K; i++){
            int[] city = in.ii();
            road.unite(city[0], city[1]);
        }
        
        UnionFind rail = new UnionFind(N+1);
        for(int i = 0; i < L; i++){
            int[] city = in.ii();
            rail.unite(city[0], city[1]);
        }
        
        ArrayList<Long> list = new ArrayList<>();
        for(int i = 1; i <= N; i++){
            long key = ((long)road.root(i)<<18) + rail.root(i);
            list.add(key);
        }
        list.sort(null);
        
        int[] ans = new int[N];
        StringBuilder sb = new StringBuilder();
        for(int i = 1; i <= N; i++){
            long key = ((long)road.root(i)<<18) + rail.root(i);
            int id = Collections.binarySearch(list, key);
            if(ans[id] == 0){
                int l = id-1;
                while(l >= 0 && list.get(l) == key){
                    l--;
                }
                int r = id+1;
                while(r < N && list.get(r) == key){
                    r++;
                }
                final int count = r-l-1;
                for(int j = l+1; j < r; j++){
                    ans[j] = count;
                }
            } 
            sb.append(ans[id]).append(' ');
        }
        out.println(sb);
    }

    static class UnionFind{
        int[] par, size;
        private final int MAX_N;
        UnionFind(int n){
            MAX_N = n;
            par = new int[n];
            size = new int[n];
            for(int i = 1; i < MAX_N; i++)
                par[i] = i;
            Arrays.fill(size, 1);
        }

        int root(int x){
            return par[x] == x ? x : (par[x] = root(par[x]));
        }

        boolean same(int x, int y){
            return root(x) == root(y);
        }

        void unite(int x, int y){
            x = root(x);
            y = root(y);
            if(x == y)
                return;
            if(x < y){
                par[y] = x;
                size[x] += size[y];
            }else{
                par[x] = y;
                size[y] += size[x];
            }
        }

        int size(int x){
            return size[root(x)];
        }
    }

    static class MyReader extends BufferedReader{
        MyReader(){
            super(new InputStreamReader(System.in));
        }

        String s(){
            try{return readLine();}catch(IOException e){return "";}
        }

        String[] ss(){
            return s().split(" ");
        }

        int i(){
            return Integer.parseInt(s());
        }

        int[] ii(){
            String[] ss = ss();
            int[] ii = new int[ss.length];
            for(int j = 0; j < ss.length; j++) ii[j] = Integer.parseInt(ss[j]);
            return ii;
        }

        ArrayList<Integer> li(){
            String[] ss = ss();
            ArrayList<Integer> li = new ArrayList<>();
            for(int j = 0; j < ss.length; j++) li.add(Integer.parseInt(ss[j]));
            return li;
        }

        long l(){
            return Long.parseLong(s());
        }

        long[] ll(){
            String[] ss = ss();
            long[] ll = new long[ss.length];
            for(int j = 0; j < ss.length; j++) ll[j] = Long.parseLong(ss[j]);
            return ll;
        }
    }
}
