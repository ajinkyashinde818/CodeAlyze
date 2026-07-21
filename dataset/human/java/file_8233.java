import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long s = 0;
        for(int i = 1 ; i <= a ; i++ ){
            if(a % i == 0 && b % i == 0){
                s = (long)i;
            }
        }
        long q = a * b / s;
        System.out.println(q);
        sc.close();
    }
}
