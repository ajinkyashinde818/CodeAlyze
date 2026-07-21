import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.next());
        int[] a = new int[n];
        int[] c = new int[n];
        int ans = 0;
        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(sc.next());
        }
        for(int i = 0; i < n; i++){
            ans += Integer.parseInt(sc.next());
        }
        for(int i = 1; i < n; i++){
            c[i] = Integer.parseInt(sc.next());
        }
        
        for(int i = 0; i < n-1; i++){
            if(a[i] +1 == a[i+1]){
                ans += c[a[i]];
            }
        }
        
        System.out.println(ans);
    }
}
