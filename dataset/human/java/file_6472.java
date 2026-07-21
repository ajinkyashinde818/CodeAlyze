import java.util.Scanner;
public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        int x,y,z,k,s,count=0;
        Scanner scan = new Scanner(System.in);
        k = scan.nextInt();
        s = scan.nextInt();
        if(s / k == 3){
            count++;
        }else{
            for(x = 0; x <= k; x++){
                for(y = 0;y<=k;y++){
                    if(s - x-y >=0 && s -x-y <=k) count++;
                }
             }
        }
        
        System.out.println(count);
    }
}
