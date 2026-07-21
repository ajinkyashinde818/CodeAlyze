import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        
        String S=sc.next();
        String x=S.substring(0,1);
        String y=S.substring(1,2);
        String z=S.substring(2,3);
        if(x.equals(y)||y.equals(z)||z.equals(x)){
            System.out.println("No");
        }else{
            System.out.println("Yes");
        }
    }
}
