import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        int num = 0;
        for (int i = Math.min(a,b); i >= 1; i--) {
            if (a % i == 0 && b % i == 0)
                num++;
            if (num == k)
                System.out.println(i);
                if(num == k)
                    break;
        }
    }
}
