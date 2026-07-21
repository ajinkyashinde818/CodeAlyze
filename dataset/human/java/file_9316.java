import java.util.*;
import java.io.*;
import java.lang.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int ans = 0;
        String p = "No";
        for (int i = 0; i<n; i++){
            int a = sc.nextInt();
            int b = sc.nextInt();

            if (a==b)
                ans++;
            else
                ans = 0;
            if (ans==3){
                p = "Yes";
                break;
            }
        }
        System.out.println(p);
    }
}
