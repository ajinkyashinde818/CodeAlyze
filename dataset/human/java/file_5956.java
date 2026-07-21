import java.util.*;
import java.math.*;
     
class Main{
    public static void main(String[] args) {
        
        try(Scanner sc = new Scanner(System.in)){
            String abc = sc.next();

            int countA = 0, countB = 0, countC = 0;

            for(int i = 0; i < 3; i++){
                String str = abc.substring(i, i + 1);
                if(str.equals("a")) countA++;
                else if(str.equals("b")) countB++;
                else if(str.equals("c")) countC++;
            }

            if(countA == 1 && countB == 1 && countC == 1){
                System.out.println("Yes");
            }else{
                System.out.println("No");
            }

        }catch(Exception e){
            e.printStackTrace();
        }        
    }
}
