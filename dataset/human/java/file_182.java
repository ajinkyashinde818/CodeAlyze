import java.util.*;

public class Main {
    public static void main(String[] args) {
//        A.solution();
//        B.solution();
//        C.solution();
//        C122.solution();
        ABC125.solutionD();
//        ABC125.solutionC();
    }
}

class A {
    static void solution() {
        Scanner sc = new Scanner(System.in);
        int A = Integer.parseInt(sc.next());
        int B = Integer.parseInt(sc.next());
        if (A > B) System.out.println(2 * A - 1);
        else if (B > A) System.out.println(2 * B - 1);
        else System.out.println(A + B);
    }
}

class B {
    static void solution() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); //num of arrays
        Integer[] mountain = new Integer[N]; // array
        for (int i = 0; i < N; i++) {
            mountain[i] = sc.nextInt();
        }
        int maxhight = 0;
        int seeview = 0;
        for (int i = 0; i < N; i++) {
            if (maxhight <= mountain[i]) {
                seeview++;
                maxhight = mountain[i];
            }
        }
        System.out.println(seeview);
    }
}

class C {
    static void solution() {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        int cnt = 0;
        for (int i = 0; i < S.length(); i++) {
            int num = S.charAt(i) - '0';
            if (i % 2 == num) cnt++;
        }
        System.out.println(Math.min(cnt, S.length() - cnt));
    }
}


class C122 {
     static void solution(){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int Q = sc.nextInt();
        String S = sc.next();
        int[] l = new int[Q];
        int[] r = new int[Q];
        for (int i=0; i<Q; i++) {
            l[i] = sc.nextInt();
            r[i] = sc.nextInt();
        }
         for (int i=0; i<Q; i++) {
            String s = S.substring(l[i]-1,r[i]);
            String temp = s.replace("AC", "");
            int occ = (s.length() - temp.length()) / 2;
            System.out.println(occ);
        }
    }
}

class ABC125 {
    static void solutionC() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long[] A = new long[N];
        for (int i=0; i<N; i++) {
            A[i] = sc.nextLong();
        }
        long[] L = new long[N+1];
        long[] R = new long[N+1];
        L[0] = 0;
        R[N] = 0;
        for (int i=1; i<N+1; i++) {
            L[i] = gcd(L[i-1],A[i-1]);
            R[N-i] = gcd(A[N-i],R[N-i+1]);
        }
        long[] M = new long[N];
        long maxValue = Long.MIN_VALUE;
        for (int i=0; i<N; i++) {
            M[i] = gcd(L[i],R[i+1]);
            if (maxValue < M[i]) maxValue = M[i];
//            System.out.println(M[i]);
        }
        System.out.println(maxValue);
    }

    static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    static void solutionD() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long[] A = new long[N];
        long ans = 0;
        long minAbsValue = Long.MAX_VALUE;
        int minusCount = 0;
        for (int i=0; i<N; i++) {
            A[i] = sc.nextLong();
            ans += Math.abs(A[i]);
            if (A[i] < 0) minusCount++;
            if (minAbsValue > Math.abs(A[i])) minAbsValue = Math.abs(A[i]);
        }
        if (minusCount % 2 == 1) {
            System.out.println(ans - 2*minAbsValue);
        } else {
            System.out.println(ans);
        }
    }
}
