import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;
public class Main {
    static List<HashSet<Integer>> group ;
    static List<HashSet<Integer>> group2 ;
    static int[] roads ;
    static int[] rialways ;
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        int n = in.nextInt();
        int k = in.nextInt();
        int l = in.nextInt();
        roads = new int[n+1];
        rialways = new int[n+1];
        group = new ArrayList<>(n+1);
        group2 = new ArrayList<>(n+1);
        String [] ans = new String[n+1];
        HashMap<String,Integer> mem = new HashMap<>();
        for(int i=1;i<=n;i++){
            roads[i]=i;
            rialways[i]=i;
        }
        for(int i =0;i<=n;i++){
            group.add(new HashSet<>());
            group2.add(new HashSet<>());
        }
        for(int i=0;i<k;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int boss1 = find_parent(roads,roads[a],a);
            int boss2 = find_parent(roads,roads[b],b);
            int mn = Math.min(boss1,boss2);
            roads[boss1]=mn;
            roads[boss2]=mn;
        }
        for(int i=0;i<l;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int boss1 = find_parent(rialways,rialways[a],a);
            int boss2 = find_parent(rialways,rialways[b],b);
            int mn = Math.min(boss1,boss2);
            rialways[boss1]=mn;
            rialways[boss2]=mn;
        }
        for(int i=1;i<=n;i++){
            int boss = find_parent(roads,roads[i],i);
            group.get(boss).add(i);
            roads[i]=boss;
            int j = boss;
            boss = find_parent(rialways,rialways[i],i);
            group2.get(boss).add(i);
            rialways[i]=boss;
            String t = Integer.toString(j)+"-"+Integer.toString(boss);
            ans[i]=t;
            if (mem.containsKey(t))
                mem.put(t,mem.get(t)+1);
            else mem.put(t,1);

        }

        for(int i=1;i<=n;i++){
            out.print(mem.get(ans[i])+" ");
        }
        out.close();
    }
    static int find_parent(int[] arr,int p,int i){
        if(p==i){
            return i;
        }
        else {
            return find_parent(arr,arr[p],p);
        }
    }

}
