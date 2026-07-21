import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int s = sc.nextInt();
        boolean b = s==Math.pow(10,9);
        for (int i=0;i<k;i++)System.out.println(s+" ");
        for (int i=k;i<n;i++){
            if(b)System.out.println(1+" ");
            else System.out.println(s+1+" ");
        }
    }
}
