import java.util.*;
class Main{
    public static void main(String[]args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int R = scan.nextInt();
        
        System.out.println(N>=10 ? R:R+100*(10-N));
        scan.close();
    }
}
