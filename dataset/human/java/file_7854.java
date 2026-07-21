import java.util.*;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long n, k;
        n = sc.nextLong();
        k = sc.nextLong();
        int[] to = new int[(int)n];
        for(int i = 0; i < n; i++){
            to[i] = sc.nextInt() - 1;
        }
        Vector<Integer> path = new Vector<>();
        boolean[] se = new boolean[(int)n];
        se[0] = true;
        path.add(0);
        int cur = 0;
        int lostt = 0;
        while(true){
            cur = to[cur];
            if(se[cur]){
                lostt = cur;
                break;
            }else{
                se[cur] = true;
                path.add(cur);
            }
        }
        /*for(int i = 0; i < path.size(); i++){
            System.out.println(path.get(i) + " ");
        }*/
        //System.out.println(lostt + " ");
        for(int i = 0; i < path.size(); i++){
            if(path.get(i) == lostt) {lostt = i; break;}
        }
        //System.out.println(lostt + " ");
        if(k < path.size()){
            System.out.println(path.get((int)k) + 1);
        }else{
            k -= lostt;
            k %= (path.size() - lostt);
            System.out.println(path.get((int)k + lostt) + 1);
        }
    }
}
