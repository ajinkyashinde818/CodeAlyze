import javax.print.DocFlavor;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class Main {

    //グローバル変数を定義
    List<char[]> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    void run() {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int goal = sc.nextInt();
        int[] pArray = new int[num];
        int[] cArray = new int[num];

        for(int i=0; i<num; i++){
            pArray[i] = sc.nextInt();
            cArray[i] = sc.nextInt();
        }

        int min = 1000;

        int sum = 0;
        int count = 0;

        for(int bit=0; bit<Math.pow(2, num); bit++){
            sum = 0;
            count = 0;
//            List<Integer> alreadyList = new ArrayList<>();

            for(int i=0; i<num; i++){
                if((1&bit>>i) == 1){
                    sum += pArray[i] * 100 * (i+1) + cArray[i];
                    count += pArray[i];
//                    alreadyList.add(i);
                }
            }

            if(sum >= goal){
                min = Math.min(min, count);
            } else {
                for(int i=0; i<num; i++){
                    int count2 = count;
                    int sum2 = sum;
                    if((1&bit>>i) != 1){
                        for(int j=0; j<pArray[i]; j++){
                            sum2 += (i+1) * 100;
                            count2++;

                            if(sum2 >= goal){
                                min = Math.min(min, count2);
                                sum2 =sum;
                                count2 = count;
                            }
                        }
                    }
                }
            }
        }
        System.out.println(min);
    }
}
