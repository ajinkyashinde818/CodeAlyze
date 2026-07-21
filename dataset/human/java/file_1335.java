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
	static int N;
	static char[][] A;
	static int M;
	static char[][] B;
	
	public static void main(String[] args) throws IOException {
		//File file = new File("input.txt");
		//Scanner sc = new Scanner(file);
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		M = sc.nextInt();
		A = new char[N][N];
		for(int i = 0; i < N; i++) A[i] = sc.next().toCharArray();
		B = new char[M][M];
		for(int i = 0; i < M; i++) B[i] = sc.next().toCharArray();
		
		for(int ii = 0; ii <= N - M; ii++){
			for(int jj = 0; jj <= N - M; jj++){
				if(match(ii, jj)){
					System.out.println("Yes");
					//System.out.println(ii + " " + jj);
					return;
				}
			}
		}
		System.out.println("No");
	}
	
	public static boolean match(int ii, int jj){
		for(int i = 0; i < M; i++){
			for(int j = 0; j < M; j++){
				if(A[i + ii][j + jj] != B[i][j])
					return false;
			}
		}
		return true;
	}
}
