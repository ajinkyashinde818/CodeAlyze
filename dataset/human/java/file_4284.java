import java.util.*;
import java.io.*;

import static java.lang.Character.isUpperCase;

public class Main {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[] A = new int[N];
        int[] B = new int[N];
        int[] C = new int[N-1];

        for(int i = 0; i < N; i++){
            A[i] = in.nextInt();
        }
        for(int i = 0; i < N; i++){
            B[i] = in.nextInt();
        }
        for(int i = 0; i < N-1; i++){
            C[i] = in.nextInt();
        }

        int totalAnswer = 0;
        for(int turn = 0; turn < N; turn++){
            // A[turn] => dish
            // 'dish' => B[dish] points milege

            int dish = A[turn];



            totalAnswer += B[dish-1];

            //Additionally Case
            int addition = 0;
            // jo hum abhi kha rahe h = A[turn] ---- i+1
            // isse pehle jo khayi = A[turn-1] --- i

            if(turn!=0 && A[turn-1] + 1 == A[turn]){
                totalAnswer+=C[(dish-1) - 1];
            }

        }
            System.out.println(totalAnswer);







        }







    }
