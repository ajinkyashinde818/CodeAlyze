import java.util.*;

public class Main{
        public static void main(String[] args){
                Scanner scan = new Scanner(System.in);
                int cntA = scan.nextInt();
                int cntB = scan.nextInt();
                int cntK = scan.nextInt();
                int tmp = 0;
                int count =0;

                if(cntA<cntB){
                        tmp = cntA;
                }else{
                        tmp = cntB;
                }

                for(int i=tmp ; i>=1 ; i--){
                        if(cntA%i==0 && cntB%i==0){
                                count += 1;
                                if(count==cntK){
                                        System.out.println(i);
                                }
                        }
                }
        }
}
