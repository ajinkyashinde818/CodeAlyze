//package Beginner120;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        int b = s.nextInt();
        int k = s.nextInt();
        int gcd = gcd(a, b);
        ArrayList<Integer> div = div(gcd);
//        int count = 0;
        System.out.println(div.get(div.size() - k));
    }

    private static int gcd(int a, int b) {
        if(b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    private static ArrayList<Integer> div (int num) {
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 1; i <= Math.sqrt(num); i++) {
            if(num % i == 0) {
                if(i == num/i) {
                    ans.add(i);
                } else {
                    ans.add(i);
                    ans.add(num/i);
                }
            }
        }
        Collections.sort(ans);
        return ans;
    }
}
