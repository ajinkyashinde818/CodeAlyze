import java.util.*;
public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args){
        D();
    }

    public static void A(){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println(6 - (a + b));
    }

    public static void B(){
    Scanner sc = new Scanner(System.in);
    int n = Integer.parseInt(sc.nextLine());
    String[] s = sc.nextLine().split("\\s+");
    StringBuilder ans = new StringBuilder();
    for(int i = 0; i < n; i++){
        ans.append(s[0].charAt(i));
        ans.append(s[1].charAt(i));

    }

    System.out.print(ans.toString());

    }

    public static void D(){
        int a = sc.nextInt();
        int b = sc.nextInt();
        //prevent overflow
        long c = a;
        c*=b;
        
        int temp;

        while((temp = a%b) != 0){
            
            a = b;
            b = temp;
        }

        System.out.println(c/b);
    }

    public static void GCD(){
//        First, if we subtract the smaller number from the larger number, the GCD doesn't change – therefore, if we keep on subtracting the number we finally end up with their GCD
//        Second, when the smaller number exactly divides the larger number, the smaller number is the GCD of the two given numbers.
        int a = sc.nextInt();
        int b = sc.nextInt();
        int temp = 0;

        while(true){
            temp = a % b;
            if (temp == 0){
                //b is the answer
                break;
            }
            b = a;
            a = temp;
        }
        System.out.println(b);
    }
}
