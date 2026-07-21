import java.util.*;
import java.io.*;
import java.lang.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();

        if (a.charAt(0) == '9' || a.charAt(1) == '9')
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}
