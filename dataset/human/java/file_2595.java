import java.util.Arrays;
import java.util.Scanner;

public class Main{

    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);
        
        char[] a = scan.nextLine().toCharArray();
        char[] b = scan.nextLine().toCharArray();

        Arrays.sort(a);
        Arrays.sort(b);

        boolean flg = false;
        for(int i=0; i<a.length; i++){
            int j = b.length - i - 1;
            if(j < 0){
                break;
            }else if(a[i] < b[j]){
                flg = true;
                break;
            }else if(a[i] == b[j] && (i+1) == a.length && a.length < b.length){
                flg = true;
            }
        }
        if(flg) System.out.println("Yes");
        else System.out.println("No");

        scan.close();
        
    }
}
