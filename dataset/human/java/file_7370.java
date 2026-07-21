import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.Arrays;
import java.util.Collections;
import java.util.ArrayList;
import java.util.List;
import java.util.HashSet;
import java.io.PrintWriter;
import java.io.OutputStream;

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

    // 標準入力数値配列用 integer ソート用
    static Integer[] inputvalInteger() throws Exception {
        String[] strarray = br.readLine().trim().split(" ");
        Integer[] intarray = new Integer[strarray.length];
        for (int i = 0; i < intarray.length; i++) {
            intarray[i] = Integer.parseInt(strarray[i]);
        }
        return intarray;
    }

    public static void main(String[] args) throws Exception {
	// write your code here
        String s = br.readLine().trim();
        int stPo = 0;

        while (s.length() > stPo){
            int endPo5 = stPo + 5;
            int endPo6 = stPo + 6;
            int endPo7 = stPo + 7;

            if (s.length() >= stPo + 7 && s.substring(stPo,endPo7).equals("dreamer") && (s.length() < stPo+10 || ! s.substring(endPo5,endPo5+5).equals("erase"))){
                stPo += 7;

            }else if(s.length() >= stPo + 6 && s.substring(stPo,endPo6).equals("eraser") && (s.length() < stPo+10 || ! s.substring(endPo5,endPo5+5).equals("erase"))){
                stPo += 6;

            }else if (s.length() >= stPo + 5 && (s.substring(stPo,endPo5).equals("dream") || s.substring(stPo,endPo5).equals("erase"))){
                stPo += 5;

            }else{
                System.out.println("NO");
                return;
            }
        }

        System.out.println("YES");
    }

}
