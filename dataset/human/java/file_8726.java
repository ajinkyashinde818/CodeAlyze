import java.io.BufferedReader;
import java.io.*;
import java.util.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Collections;
import java.util.Arrays;

public class Main {
	public static void main(final String[] args){
    
    final Scanner sc = new Scanner(System.in);
    //final List<Integer> list = new ArrayList<>();
    //final List<Integer> list2 = new ArrayList<>();
    //final List<Long> list3 = new ArrayList<>();

    int a = sc.nextInt();
    int b = sc.nextInt();
    int k = sc.nextInt();
    int count = 0;
    int high = 0;
    if(a >= b){
        high = a;
    }else{
        high = b;
    }

    for(int i = high; i > 0 ; i--){
        if(a % i == 0 && b % i == 0){
            count++;
        }
        if(k == count){
            System.out.println(i);
            System.exit(0);
        }
    }

    




    







}
}
