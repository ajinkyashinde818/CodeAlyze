import java.io.BufferedReader;
import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Collections;

public class Main {
	public static void main(final String[] args){
    
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int r = sc.nextInt();

    if(n >= 10){
        System.out.println(r);
    }else{
        System.out.println(r + (100*(10-n)));
    }
    }
}
