import java.util.*;

public class Main{
    static Scanner sc = new Scanner(System.in);
        
    public static void main(String[] args) {
        int n = Integer.parseInt(sc.nextLine());
        int count = 0;
        for(int i = 0;i<n;i++){
            String temp = sc.nextLine();
            if(temp.charAt(0) == temp.charAt(2)){
                count++;
            }else{
                count = 0;
            }
            if(count == 3){
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }
}
