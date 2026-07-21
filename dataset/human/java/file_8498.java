import java.io.*;
import  java.util.*;

import static java.lang.System.in;

class Main{
    public static void main(String[] args)throws IOException{
        BufferedReader reader = new BufferedReader(new InputStreamReader(in));
        String[] buf = reader.readLine().split(" ");
        int n = Integer.parseInt(buf[0]), K = Integer.parseInt(buf[1]), L = Integer.parseInt(buf[2]);
        int[] idRoad = new int[n+1], idRail = new int[n+1];;
        for(int i=1;i<=n;i++) idRoad[i]=idRail[i]=i;
        for(int i=0;i<K+L;i++){
            buf = reader.readLine().split(" ");
            int p = Integer.parseInt(buf[0]), q = Integer.parseInt(buf[1]);
            if(i<K) union(p,q,idRoad);
            else union(p,q,idRail);
        }
        HashMap<String,Integer> rec = new HashMap<>();
        for(int i=1;i<=n;i++){
            String key = getKey(i,idRoad,idRail);
            rec.put(key,rec.getOrDefault(key,0)+1);
        }
        PrintWriter out = new PrintWriter(System.out);
        for(int i=1;i<=n;i++){
            String key = getKey(i,idRoad,idRail);
            out.print(rec.get(key));
            out.print(" ");
        }
        out.flush();
    }
    static String getKey(int i, int[] idRoad, int[] idRail){
        return Integer.toString(find(i,idRoad))+" "+Integer.toString(find(i,idRail));
    }
    static int find(int p, int[] id){
        while(p!=id[p]){
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }
    static void union(int p, int q, int[] id){
        int i = find(p, id), j = find(q, id);
        if(i==j) return;
        id[j] = i;
    }
}
