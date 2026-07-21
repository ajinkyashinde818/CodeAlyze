import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
//		executeCountBalls();
//		executeTaxIncrease();
		executeStringFormation();
	}

	private static void execute() {

		Scanner in = new Scanner(System.in);

		try {
			String s1 = in.nextLine();
			String s2 = in.nextLine();
			String s3 = in.nextLine();

			int  a = Integer.parseInt(s1);
			String[] s2Array = s2.split(" ");
			int b = Integer.parseInt(s2Array[0]);
			int c = Integer.parseInt(s2Array[1]);

			int sum  = a + b + c;

//			System.out.println(a + "," + b + "," + c );

			System.out.println(sum + " " + s3);
		} catch (NumberFormatException e) {
			// TODO 自動生成された catch ブロック
			System.out.println("");
//			e.printStackTrace();
		}

	}

	public static void execute_product() {

		Scanner in = new Scanner(System.in);

		try {
			int a  = in.nextInt();
			int b  = in.nextInt();

			if( (a*b)%2 == 0 ) {
				System.out.println("Even");
			} else {
				System.out.println("Odd");
			}
		} catch (Exception e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}
	}

	public static void executeCountBalls() {
		Scanner in = new Scanner(System.in);

		try {
			long N = in.nextLong();
			long A = in.nextLong();
			long B = in.nextLong();

			long surplus = N%(A+B);
			long surplusA = surplus >= A ? A : surplus;

			 long countA = N/(A+B) * A + surplusA;

			System.out.println(countA);
		} catch (Exception e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}
	}


	public static final int TAX_RATE_8 = 8;
	public static final int TAX_TATE_10 = 10;

	public static void executeTaxIncrease(){

		Scanner in = new Scanner(System.in);

		double tax8 = (double)in.nextInt();
		double tax10 = (double)in.nextInt();

		int taxExclude_min = (int)Math.ceil((tax8 * 100)/TAX_RATE_8);

		int taxExclude_max = 0;
		if( ((tax8 + 1)*100)%8 == 0 ) {
			taxExclude_max = (int)(((tax8 + 1) * 100)/TAX_RATE_8 - 1);
		}	else {
			taxExclude_max = (int)Math.floor(((tax8 + 1) * 100)/TAX_RATE_8);
		}

//		System.out.println(taxExclude_min + " " + taxExclude_max);

		int taxExclude_fix = -1;
		for( int val = taxExclude_min; val <= taxExclude_max; val++) {
			if ( (int)Math.ceil(val/TAX_TATE_10) == tax10 ) {
				taxExclude_fix = val;
				break;
			}
		}
		System.out.println(taxExclude_fix);
	}



	private static final int ENTRY_HEAD = 0x0;
	private static final int ENTRY_TAIL = 0xFFFFFFFF;
	private static int headFlag = ENTRY_HEAD;

	public static void executeStringFormation() {


//long start = System.currentTimeMillis();

		String s1 = null;
		String s2 = null;
		int num = 0;
		List<String> queryList = new ArrayList<String>();

		if( false ) {
			Scanner in = new Scanner(System.in);

			s1 = in.nextLine();
			s2 = in.nextLine();
			num =Integer.parseInt(s2);

			for(  int i=0; i<num; i++ ) {
				queryList.add(in.nextLine());
			}

		} else {

			try {

				BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));

				s1 = stdin.readLine();
				s2 = stdin.readLine();
				num = Integer.parseInt(s2);

				for(int i = 0;i<num;i++) {
					queryList.add(stdin.readLine());
				}
			} catch (NumberFormatException e) {
				// TODO 自動生成された catch ブロック
				e.printStackTrace();
			} catch (IOException e) {
				// TODO 自動生成された catch ブロック
				e.printStackTrace();
			}
		}
//long p1 = System.currentTimeMillis();

		StringBuilder sbHeader = new StringBuilder();
		StringBuilder sbTail = new StringBuilder();
		StringBuilder sbMiddle = new StringBuilder();
		sbMiddle.append(s1);

		StringBuilder sbMerged = new StringBuilder();


		for( int i=0; i<num; i++ ) {
			String query = queryList.get(i);

			String[] queryArray = query.split(" ");
			if( "1".equals(queryArray[0]) ) {
				// 反転
				exchange(~headFlag);

			} else if( "2".equals(queryArray[0]) ) {
				// 追加

				if( "1".equals(queryArray[1] )) {
					// 先頭追加
					if(  headFlag == ENTRY_HEAD) {
						addString(sbHeader, queryArray[2]);
					} else {
						addString(sbTail, queryArray[2]);
					}

				} else if( "2".equals(queryArray[1])) {
					// 末尾追加
					if( headFlag == ENTRY_HEAD ) {
						addString(sbTail, queryArray[2]);
					} else {
						addString(sbHeader, queryArray[2]);
					}
				} else {
					;
				}
			} else {
				;
			}
		}

//long p2 = System.currentTimeMillis();
		// 結合処理
		if( headFlag == ENTRY_HEAD ) {
		    sbMerged.append(sbHeader.reverse());
		    sbMerged.append(sbMiddle);
		    sbMerged.append(sbTail);
		} else {
			sbMerged.append(sbTail.reverse());
			sbMerged.append(sbMiddle.reverse());
			sbMerged.append(sbHeader);
		}

//		System.out.println(sb.toString());
		try {
			PrintWriter pw = new PrintWriter(System.out);
//			PrintWriter pw = new PrintWriter("output.txt");
			String str = sbMerged.toString();
			pw.println(str);

//			long end = System.currentTimeMillis();

//			pw.println("start-end " + (end-start) + "ms");
//			pw.println("start-p1 " + (p1-start) + "ms");
//			pw.println("p1-p2 " + (p2-p1) + "ms");
//			pw.println("p2-end " + (end-p2) + "ms");

			pw.flush();
			pw.close();

		} catch (Exception e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		}


	}

	private static void exchange(int entry){
		headFlag = entry;
	}

	private static void addString(StringBuilder sbuilder, String c) {
		sbuilder.append(c);
	}

}
