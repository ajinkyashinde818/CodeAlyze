import java.util.*;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int ans = 0;
        int a[] = new int[n];
        int tmp = 0;
        int tmp2 = 0;
        for(int i = 0;i<n;i++){
            tmp = Integer.parseInt(sc.next());
            if(tmp == tmp2 + 1){
                a[tmp2] = 1;
            }
            tmp2 = tmp;
        }
        for(int i = 0;i<n;i++){
            ans += Integer.parseInt(sc.next());
        }
        for(int i = 1;i < n;i++){
            tmp = Integer.parseInt(sc.next());
            if(a[i] != 0){
                ans += tmp;
            }
        }
        System.out.println(ans);
    }
}
