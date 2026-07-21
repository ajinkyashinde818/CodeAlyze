import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        int s=sc.nextInt();
        if(s==1000000000){
            
        }
        for(int i=0;i<n;i++){
            if(i<k){
                System.out.print(s+" ");
            }else{
                if(s==1000000000){
                    System.out.print(1+" ");
                }else{
                    System.out.print(1000000000+" ");
                }
                
            }
        }
        System.out.println();
 
    }



}
