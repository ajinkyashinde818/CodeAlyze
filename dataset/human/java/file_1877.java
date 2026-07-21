import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileReader;
import java.io.FileWriter;

import java.util.*;
import java.util.stream.LongStream;

public class Main {
    // 標準入力
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    // 標準入力数値配列用 int
    static int[] inputval() throws Exception {
        String[] strarray = br.readLine().trim().split(" ");
        int[] intarray = new int[strarray.length];
        for (int i = 0; i < intarray.length; i++) {
            intarray[i] = Integer.parseInt(strarray[i]);
        }
        return intarray;
    }

    /* 標準入力数値配列用 long */
    static long[] inputLongArr() throws Exception {
        String[] strarray = br.readLine().trim().split(" ");
        long[] longarray = new long[strarray.length];
        for (int i = 0; i < longarray.length; i++) {
            longarray[i] = Long.parseLong(strarray[i]);
        }
        return longarray;
    }

    // 標準入力数値リスト用 int
    static List<Integer> inputIntList() throws Exception {
        List<String> strList = Arrays.asList(br.readLine().trim().split(" "));
        List<Integer> intList = new ArrayList<Integer>();
        for (String elem : strList){
            intList.add(Integer.parseInt(elem));
        }
        return intList;
    }

    // 標準入力数値配列用 integer 降順ソート用
    static Integer[] inputvalInteger() throws Exception {
        String[] strarray = br.readLine().trim().split(" ");
        Integer[] intarray = new Integer[strarray.length];
        for (int i = 0; i < intarray.length; i++) {
            intarray[i] = Integer.parseInt(strarray[i]);
        }
        return intarray;
    }

    /*標準入力long*/
    static long inputLong() throws Exception {
        return Long.parseLong(br.readLine());
    }

    /*標準入力long*/
    static int inputInt() throws Exception {
        return Integer.parseInt(br.readLine());
    }



    public static void main(String[] args) throws Exception {
        // write your code here
        long [] dg = inputLongArr();
        long d = dg[0];
        long g = dg[1];
        int [][] pcl = new int [(int)d][2];
        for(int i=0; i<d; i++){
            int [] pc = inputval();
            pcl[i] = pc;
        }
        long cnt = Integer.MAX_VALUE;

        // ボーナスがもらえるかどうかで全探索
        for(int i=0; i<Math.pow(2,d);i++){
            long sum = 0;
            long tmpC = 0;
            // ボーナス受け取り判定 -1 未
            int [] done = new int [(int)d];
            for (int j=0; j<d; j++){
                done[j] = -1;
            }

            for (int j=0; j<d; j++) {
                if ((1&i>>j) == 1){
                    sum += pcl[j][1] + pcl[j][0] * 100 * (j+1);
                    tmpC += pcl[j][0];
                    done[j] = 0;
                }
            }

            // 加算するボーナスなし通常の値を決定
            int ci = -1;
            for (int j=(int)d-1; j>=0; j--){
                if(done[j] == -1){
                    ci = j;
                    break;
                }
            }
            // ボーナスなし通常の値を加算
            if (ci != -1){
                for (int j=1; j<pcl[ci][0]; j++){
                    if (sum >= g){
                        break;
                    }
                    sum += 100 * (ci +1);
                    tmpC ++;
                }
            }

            if (sum >= g){
                cnt = Math.min(cnt, tmpC);
            }
        }


        System.out.println(cnt);







    }

}
