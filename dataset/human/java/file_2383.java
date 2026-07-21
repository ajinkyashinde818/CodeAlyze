import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String festival = sc.nextLine();
        
        System.out.println(festival.substring(0,festival.length()-8));
    }
}
