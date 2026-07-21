import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int count = 0;
        int a = Integer.parseInt(sc.next());
        int b = Integer.parseInt(sc.next());
        int k = Integer.parseInt(sc.next());
        sc.close();
        for(int i=a;i>=1;i--){
            if(a%i == 0 && b%i==0){
                count++;
            }
            if(count==k){
                System.out.println(i);
                return;
            }
        }
        
    }
    
}
