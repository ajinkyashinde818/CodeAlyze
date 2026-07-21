import java.util.*;
import java.io.*;

/*
   AtCoder contest code
   coder : yoichidon
 */

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int anti = sc.nextInt();
        int delAnti = sc.nextInt();
        int poison = sc.nextInt();

        int eatPoison = Math.min(poison, anti+delAnti+1);
        System.out.println(delAnti+eatPoison);


    }
}
