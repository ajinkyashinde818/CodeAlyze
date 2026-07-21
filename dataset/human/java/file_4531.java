import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        sc.close();

        if(c <= a+b+1){
            System.out.println(c+b);
        }else{
            System.out.println(a+b*2+1);
        }
    }
}
