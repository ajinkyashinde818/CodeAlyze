import java.util.*;

public class Main {
    
    static int n;
    static int m;
    static long x;
    static long[] cost;
    static long[][] exp;
    static long min;
    static List<Long> now;

    static void dfs(int i, long c, List<Long> list){
        if(overX(list)){
            if(min == -1 || min > c){
                min = c;
            }
            return;
        }
        if(i >= n){
            return;
        }
        List<Long> newList = new ArrayList<>();
        newList.addAll(now);
        dfs(i + 1, c, list);
        newList = new ArrayList<>();
        for(int j=0; j<m; j++){
            newList.add(list.get(j) + exp[i][j]);
        }
        dfs(i + 1, c + cost[i], newList);
    }
    
    static boolean overX(List<Long> list){
        boolean flag = true;
        for(int i=0; i<m; i++){
            if(list.get(i) < x){
                flag = false;
                break;
            }
        }
        return flag;
    }

    public static void main(String[] args) throws Exception{

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();
        x = sc.nextLong();

        cost = new long[n];
        exp = new long[n][m];
        now = new ArrayList<>();
        for(int i=0; i<m; i++){
            now.add(0L);
        }
        min = -1;

        for(int i=0; i<n; i++){
            cost[i] = sc.nextLong();
            for(int j=0; j<m; j++){
                exp[i][j] = sc.nextLong();
            }
        }

        dfs(0, 0, now);
        System.out.println(min);
    }
}
