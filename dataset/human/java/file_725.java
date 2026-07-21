import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        short i = scanner.nextShort();
        short j = scanner.nextShort();
        if (i > 9){
            System.out.println(j);
        }else {
            System.out.println(j+1000-100*i);
        }

    }
    
}
