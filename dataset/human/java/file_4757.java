import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String n = sc.next();
        int[] a = new int[n.length()+1];
        for (int i = 1; i < n.length()+1; i++) {
            a[i] = Integer.parseInt(n.substring(i-1, i));
        }
        long ans = 0;
        int[] b = new int[n.length()+1];
        for (int i = a.length-1; i > 0; i--) {
            a[i] += b[i];
            if(5 < a[i]){
                b[i-1]++;
                ans += 10 - a[i];
            }else if(a[i] == 5 && 5 <= a[i-1]){
                b[i-1]++;
                ans += 10 - a[i];
            }else{
                ans += a[i];
            }
        }
        ans += b[0];
        System.out.println(ans);
        sc.close();

    }

}
