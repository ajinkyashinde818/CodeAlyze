import java.io.File;
import java.io.FileInputStream;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Deque;
import java.util.HashMap;
import java.util.List;
import java.util.Map.Entry;

public class Main {
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		
		String S = sc.next();
		String[] list = {"eraser", "erase", "dreamer", "dream"};
		for(String m : list){
			while(true){
				int index = S.indexOf(m);
				if(index == -1) break;
				S = S.replace(m, "");
			}
		}
		
		System.out.println(S.equals("") ? "YES" : "NO");
	}
}
