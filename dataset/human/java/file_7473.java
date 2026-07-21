/*
 * 英小文字からなる文字列 S が与えられます。 Tが空文字列である状態から始め、以下の操作を好きな回数繰り返すことで S=T とすることができるか判定してください。
 * 
 *    T の末尾に dream dreamer erase eraser のいずれかを追加する。
 */

import java.util.*;
	public class Main{
        public static void main(String[] args){
            Scanner sc = new Scanner(System.in);
            // 入力を一文字ずつにする
            sc.useDelimiter("");
            // 10文字読み込む
            String s = sc.next();
            s = getString(s, 9, sc);
            
            // 改行文字だけになるまで続ける
            while(s.length() > 1){
            	// eraserが先頭にあるならそれを消し、10文字になるまで読み込む
            	if(s.length() >=6 && s.substring(0, 6).equals("eraser")){
            		s = s.substring(6);
            		s = getString(s, 6, sc);
            	// eraseが先頭にあるならそれを消し、10文字になるまで読み込む、dreamが先頭にある、かつdreamerが先頭にないならdreamを消し、10文字になるまで読み込む、dreameraseが先頭にあるならdreamを消し、10文字になるまで読み込む
            	}else if((s.length() >=5 && s.substring(0, 5).equals("erase")) || (s.length() >=6 && s.substring(0, 5).equals("dream") && !s.substring(0, 6).equals("dreame")) || (s.length() >=10 && s.substring(0, 10).equals("dreamerase"))){
            		s = s.substring(5);
            		s = getString(s, 5, sc);
            	// 残りが、(dreamまたはdreamer) + 改行文字ならばおしまい
            	}else if((s.length() == 6 && s.substring(0, 5).equals("dream")) || (s.length() == 8 && s.substring(0, 7).equals("dreamer"))){
            		s = "";
            	// dreamerが先頭にある、かつdreameraseが先頭にないならdreamerを消し、10文字になるまで読み込む
            	}else if(s.length() >=10 && s.substring(0, 7).equals("dreamer") && !s.substring(0, 10).equals("dreamerase")){
            		s = s.substring(7);
            		s = getString(s, 7, sc);
            	// それ以外なら題の操作では生成できない文字列なのでNOを出力してreturn
            	}else{
            		System.out.println("NO");
                    sc.close();
                    return;
            	}
            }
            
            // 改行文字だけになったら題の操作で生成できるということなのでYESを出力
            System.out.println("YES");
            sc.close();
        }
        
        // n文字分入力を読み取ってsに追加する関数getString
        public static String getString(String s, int n, Scanner sc){
        	// 改行文字を読みとったらもうそれ以上は読み込まない
        	if(!s.substring(s.length()-1).equals("\n")){
        		for(int i=0; i<n && !s.substring(s.length()-1).equals("\n"); i++){
        			s += sc.next();
        		}
        	}
            
            return s;
        }
    }
