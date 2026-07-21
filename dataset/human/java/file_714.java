import java.util.Scanner;
public class Main{
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        int b = scan.nextInt();
        int c;
        if(a >= 10){
            c = b;
            System.out.println(c);
        }else{
            c = b + 100*(10 - a);
            System.out.println(c);
        }
    }
}
