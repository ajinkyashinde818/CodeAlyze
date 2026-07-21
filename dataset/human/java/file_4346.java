import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
      	int[] B = new int[N];
      	int[] C = new int[N-1];
      	int Result = 0;
		
		for(int i = 0; i<A.length; i++) {
			A[i] = sc.nextInt();
		}	
      	for(int i = 0; i<B.length; i++) {
			B[i] = sc.nextInt();
		}
      	for(int i = 0; i<C.length; i++) {
			C[i] = sc.nextInt();
		}
		for(int i = 0; i<A.length; i++) {
			switch(A[i]){
              case 1:
                Result += B[0];
                break;
              case 2:
                Result += B[1];
                if (i>0 && A[i-1]==1)
                {
                  Result += C[0];
                }                  
                break;
              case 3:  
                Result += B[2];
                if (i>0 && A[i-1]==2)
                {
                  Result += C[1];
                }
                break;
              case 4:
                Result += B[3];
                if (i>0 && A[i-1]==3)
                {
                  Result += C[2];
                }
                break;
              case 5:
                Result += B[4];
                if (i>0 && A[i-1]==4)
                {
                  Result += C[3];
                }
                break;
              case 6:
                Result += B[5];
                if (i>0 && A[i-1]==5)
                {
                  Result += C[4];
                }
                break;
              case 7:
                Result += B[6];
                if (i>0 && A[i-1]==6)
                {
                  Result += C[5];
                }
                break;
              case 8:
                Result += B[7];
                if (i>0 && A[i-1]==7)
                {
                  Result += C[6];
                }
                break;
              case 9:
                Result += B[8];
                if (i>0 && A[i-1]==8)
                {
                  Result += C[7];
                }
                break;
              case 10:
                Result += B[9];
                if (i>0 && A[i-1]==9)
                {
                  Result += C[8];
                }
                break;
              case 11:
                Result += B[10];
                if (i>0 && A[i-1]==10)
                {
                  Result += C[9];
                }
                break;
              case 12:
                Result += B[11];
                if (i>0 && A[i-1]==11)
                {
                  Result += C[10];
                }
                break;
              case 13:
                Result += B[12];
                if (i>0 && A[i-1]==12)
                {
                  Result += C[11];
                }
                break;
              case 14:
                Result += B[13];
                if (i>0 && A[i-1]==13)
                {
                  Result += C[12];
                }
                break;
              case 15:
                Result += B[14];
                if (i>0 && A[i-1]==14)
                {
                  Result += C[13];
                }
                break;
              case 16:
                Result += B[15];
                if (i>0 && A[i-1]==15)
                {
                  Result += C[14];
                }
                break;
              case 17:
                Result += B[16];
                if (i>0 && A[i-1]==16)
                {
                  Result += C[15];
                }
                break;
              case 18:
                Result += B[17];
                if (i>0 && A[i-1]==17)
                {
                  Result += C[16];
                }
                break;
              case 19:
                Result += B[18];
                if (i>0 && A[i-1]==18)
                {
                  Result += C[17];
                }
                break;
              case 20:
                Result += B[19];
                if (i>0 && A[i-1]==19)
                {
                  Result += C[18];
                }
                break;
            }
        }
        System.out.println(Result);
	}
}
