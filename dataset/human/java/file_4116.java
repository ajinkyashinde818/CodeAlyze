import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        
        Scanner in = new Scanner(System.in);
        int variety = in.nextInt();
        int[] num = new int[variety];
        int[] addpoint = new int[variety];
        
        int sumpoint = 0;
        for (int i = 0;i < variety;i++){
            num[i] = in.nextInt() - 1; 
        }
        for (int i = 0;i < variety;i++){
            sumpoint += in.nextInt(); 
        }        
        for (int i = 0;i < variety - 1;i++){
            addpoint[i] = in.nextInt(); 
        }
        
        int memdish = -1;
        for (int i = 0;i < variety;i++){
            if (memdish  == num[i]){
                sumpoint += addpoint[num[i] - 1];
            }
            memdish = num[i] + 1;
        } 
        System.out.println(sumpoint);

    }
}
