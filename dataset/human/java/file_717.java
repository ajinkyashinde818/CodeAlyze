import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = sc.nextInt();
        if(n < 10){
            r += (10 - n) * 100;
        }
        System.out.println(r);
        sc.close();
    }
}
