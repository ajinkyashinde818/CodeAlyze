import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args){
        FastScanner fsc=new FastScanner();
        int n=fsc.nextInt();
        int k=fsc.nextInt(), l=fsc.nextInt();
        UnionFindTree road=new UnionFindTree(n);
        for(int i=0;i<k;i++){
            int p=fsc.nextInt()-1, q=fsc.nextInt()-1;
            road.unite(p, q);
        }
        UnionFindTree rail=new UnionFindTree(n);
        for(int i=0;i<l;i++){
            int r=fsc.nextInt()-1, s=fsc.nextInt()-1;
            rail.unite(r, s); 
        }
        fsc.close();
        HashMap<Integer, HashSet<Integer>> roadgr=new HashMap<>();
        for(int i=0;i<n;i++){
            if(!roadgr.containsKey(road.root(i))){
                roadgr.put(road.root(i), new HashSet<>());
            }
            roadgr.get(road.root(i)).add(i);
        }
        int[] ans=new int[n];
        for(HashSet<Integer> set:roadgr.values()){
            HashMap<Integer, HashSet<Integer>> railgr=new HashMap<>();
            for(int e:set){
                if(!railgr.containsKey(rail.root(e))){
                    railgr.put(rail.root(e), new HashSet<>());
                }
                railgr.get(rail.root(e)).add(e);
            }
            for(HashSet<Integer> railSet:railgr.values()){
                int size=railSet.size();
                for(int e:railSet){
                    ans[e]=size;
                }
            }
        }
        for(int i=0;i<n;i++){
            System.out.print(ans[i]+" ");
        }
        System.out.print("\n");
    }
    static class UnionFindTree{
        int[] parent, rank, num;
        public UnionFindTree(int n){
            parent=new int[n];
            rank=new int[n];
            num=new int[n];
            for(int i=0;i<n;i++){
                parent[i]=i;
                num[i]=1;
            }
        }
        public int root(int x){
            if(parent[x]==x) return x;
            parent[x]=root(parent[x]);
            return parent[x];
        }
        public boolean same(int x, int y){
            return root(x)==root(y);
        }
        public boolean unite(int x, int y){
            int xr=root(x);
            int yr=root(y);
            if(xr==yr) return false;
            if(rank[xr]<rank[yr]){
                parent[xr]=yr;
                num[yr]+=num[xr];
            }
            else{
                parent[yr]=xr;
                num[xr]+=num[yr];
                if(rank[xr]==rank[yr]) rank[xr]++;
            }
            return true;
        }
        public int size(int x){
            return num[root(x)];
        }
    }
    static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;
        private boolean hasNextByte(){
            if(ptr<buflen) return true;
            else{
                ptr = 0;
                try{
                    buflen = in.read(buffer);
                }
                catch(IOException e){
                    e.printStackTrace();
                }
                if(buflen<=0) return false;
            }
        return true;
        }
        private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
        private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
        public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while(isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }
        public long nextLong() {
            if (!hasNext()) throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || '9' < b) throw new NumberFormatException();
            while(true){
                if ('0' <= b && b <= '9') {
                    n *= 10;
                    n += b - '0';
                }
                else if(b == -1 || !isPrintableChar(b)) return minus ? -n : n;
                else throw new NumberFormatException();
                b = readByte();
            }
        }
        public int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
            return (int) nl;
        }
        public double nextDouble() { return Double.parseDouble(next());}
        public void close(){
            try{in.close();}
            catch(IOException e){e.printStackTrace();}
        }
    }
}
