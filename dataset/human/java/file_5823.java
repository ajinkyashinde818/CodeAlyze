import java.util.Scanner;

public class Main{

     public static void main(String []args){
        Scanner input = new Scanner(System.in);
        String s = input.nextLine();
        if (s.equals("abc") || s.equals("acb") || s.equals("bac") || s.equals("bca") || s.equals("cba") || s.equals("cab")){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
     }
}
