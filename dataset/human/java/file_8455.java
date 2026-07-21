//package com.beginner.b049;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {

    public static void main(String args[]) throws Exception
    {
        Scanner sc = new Scanner(System.in);

        int N,K,L;
        N = sc.nextInt();
        K =sc.nextInt();
        L = sc.nextInt();

        UnionFind rail = new UnionFind(N);
        UnionFind road = new UnionFind(N);

        for(int i = 0 ;i < K;i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            rail.union(x-1,y-1);
        }

        for(int i = 0 ;i < L;i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            road.union(x-1,y-1);
        }

        //ot if doing as below
//        for(int i=0; i < N; i++){
//            int cnt = 0;
//            for(int j=0; j< N; j++){
//                if(road.isConnected(i,j)&&rail.isConnected(i,j)){
//                    cnt++;
//                }
//            }
//            if(i!=N-1)
//                System.out.print(cnt+ " ");
//            else
//                System.out.println(cnt);
//        }

        TreeMap<Long,Integer> map = new TreeMap<>();

        for(int i=0; i<N; i++){
            long key = (long)road.find(i)*N+rail.find(i);
            Integer cnt = map.get(key);
            if (cnt!=null){
                map.put(key, cnt+1);
            }
            else {
                map.put(key,1);
            }
        }

        for(int i=0; i<N; i++){
            long key = (long) road.find(i)*N+rail.find(i);
            if(i!=N-1)
                System.out.print(map.get(key)+" ");
            else
                System.out.println(map.get(key));
        }


        sc.close();
    }

    private static class UnionFind{
        int sz[];
        int id[];
        int count;

        public UnionFind(int n){
            create(n);
        }

        public void create (int n){
            id = new int[n];
            sz = new int [n];
            for(int i=0;i<n;i++){
                id[i] = i;
                sz[i] = 1;
            }
            count = n;
        }

        public int find(int n){
            int tmp = n ;
            while(tmp!=id[tmp]){
                id[tmp] = id[id[tmp]];
                tmp = id[tmp];
            }

            return tmp;
        }

        public void union(int x,int y){

            int xRoot = find(x);
            int yRoot = find(y);

            if(xRoot!=yRoot){
                if (sz[xRoot]<sz[yRoot]){
                    id[xRoot] = yRoot;
                    sz[yRoot] += sz[xRoot];
                }
                else{
                    id[yRoot] = xRoot;
                    sz[xRoot] += sz[yRoot];
                }
                count --;
            }

        }

        public boolean isConnected(int x, int y){
            return find(x) == find(y) ;
        }

    }

}
