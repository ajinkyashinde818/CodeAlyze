import java.util.*;
import java.io.*;
import java.lang.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        int c = 0;
        int d = 0;
        switch (a) {
            case "A":
                c = 10;
                break;
            case "B":
                c = 11;
                break;
            case "C":
                c = 12;
                break;
            case "D":
                c = 13;
                break;
            case "E":
                c = 14;
                break;
            case "F":
                c = 15;
                break;
        }

        switch (b) {
            case "A":
                d = 10;
                break;
            case "B":
                d = 11;
                break;
            case "C":
                d = 12;
                break;
            case "D":
                d = 13;
                break;
            case "E":
                d = 14;
                break;
            case "F":
                d = 15;
                break;
        }

        if (c<d)
            System.out.println('<');
        else if (c>d)
            System.out.println('>');
        else
            System.out.println('=');
    }
}
