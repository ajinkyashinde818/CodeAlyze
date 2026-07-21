//package com.beginner.b051;
import java.util.Scanner;

public class Main {

    public static void main(String args[]) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int S = sc.nextInt();
        int sum = 0;
        for(int i=0;i<=K;i++){
            for(int j=0;j<=K;j++){
                if(S-i-j>=0&&S-i-j<=K){
                    //System.out.println(i+" "+j+" " + (S-i-j));
                    sum++;
                }
            }

        }
//        if(S%3==0&&S/3<=K){
//            sum-=2;
//        }
        System.out.println( sum);
        sc.close();
    }

}
