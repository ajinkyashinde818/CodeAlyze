import java.util.*;

public class Main{
    public static  void main(String[] args){
        Scanner sc = new Scanner(System.in);
        char[] b = sc.nextLine().toCharArray();
        Arrays.sort(b);
        if(b[0] == 'a' &&b[1] == 'b' &&b[2] == 'c'){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}
