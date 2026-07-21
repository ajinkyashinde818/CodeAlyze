import java.util.*;
class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
    
        int k = sc.nextInt();
        int s = sc.nextInt(); // 最大値
        sc.close();
       
        int index = 0;
        int x,y,z;

        for (x = 0;x <= k;x++) {
            for(y = 0;y <= k;y++) {
                z = s - x - y; // 最大値から x と y を引いて z　の数を求める。
                    if(0 <= z && z <= k) {
                        index++;
                    } 
                
            }
        }
        
        System.out.print(index);
        
    }

}
