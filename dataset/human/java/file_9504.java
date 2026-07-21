/*
    Author: Anthony Ngene
    Created: 19/09/2020 - 13:04
*/

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        boolean isValid = false;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int a = in.nextInt(), b = in.nextInt();
            if (a == b) {
                count++;
                if (count >= 3)
                    isValid = true;
            } else {
                count = 0;
            }
        }
        System.out.println(isValid ? "Yes" : "No");
    }
}
