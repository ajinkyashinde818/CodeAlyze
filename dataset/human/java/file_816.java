import java.util.*;
import java.io.*;

import static java.lang.Character.isUpperCase;

public class Main {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int R = in.nextInt();

        if(N>=10)
        {
            System.out.println(R);
        }
        else
            {
                System.out.println(R+100*(10-N));
            }





    }


 }
