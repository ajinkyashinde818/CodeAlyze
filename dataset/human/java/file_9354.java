import java.util.*;
public class Main {
    public static void main(String [] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int cnt = 0;
        for(int i=0;i<N;i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            if(a==b)cnt++;
            else cnt = 0;
            if(cnt==3) break;
        }
        if(cnt==3) System.out.println("Yes");
        else System.out.println("No");
    }
}
