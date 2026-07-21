#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <fstream>
#include <sstream>
#include <math.h>
#include <queue>
#include <stack>
#include <math.h>


using namespace std;


//-------------------------------------------------------------------------------------
/*2点[(x1,y1),(x2,y2)]を入力し二点を通る直線ax+by+cの(a,b,c)を返す,  */
/*x1==x2ならfalseを返す*/
/*falseならばx=cの形の直線*/
void straight_line_passing_through_the_two_points(double x1, double y1, double x2, double y2, double *a, double *b, double *c){
    *a=(y2-y1);
    *b=-(x2-x1);
    *c=y2*(x2-x1)-x2*(y2-y1);
}

//-------------------------------------------------------------------------------------
/*(x,y)を通るa1x+b1y+c1=0に垂直な直線a2x+b2y+c2=0を返す*/
bool vertical_straight_line(double x, double y, double a1, double b1, double c1, double *a2, double *b2, double *c2){
    if(a1*x+b1*y+c1==0)return false;
    *a2 = -b1;
    *b2 = a1;
    *c2 = b1*x - a1*y;
    return true;
}

int intersection_and_parallel(double a1, double b1, double c1, double a2, double b2, double c2, double *x, double *y){
    if(a1*b2==a2*b1)return false;//平行の判定
    
    *x = (b1*c2-b2*c1)/(a1*b2-a2*b1);
    *y = (a2*c1-a1*c2)/(a1*b2-a2*b1);
    
    return true;
}

double distance_between_the_two_pointss(double x1,double y1, double x2, double y2){
    return  sqrt(fabs((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}

/*点(p_x,p_y)と線分(x1,y1)(x2,y2)の距離*/
/* straight_line_passing_through_the_two_points */
/* vertical_straight_line */
/* intersection_and_parallel */
double distance_between_the_line_segment_and_point(double p_x, double p_y, double x1, double y1, double x2, double y2){
    double a,b,c;//(x1,y1)(x2,y2)を通る直線
    straight_line_passing_through_the_two_points(x1, y1, x2, y2, &a, &b, &c);
    double a2,b2,c2;//直線ax+by+c=0に垂直な直線
    double v_x, v_y;//二つの直線の交点
    bool is_not_parallel = vertical_straight_line(p_x, p_y, a, b, c, &a2, &b2, &c2);
    intersection_and_parallel(a, b, c, a2, b2, c2, &v_x, &v_y);
    
    if(is_not_parallel){
        if(min(x1,x2)<=v_x&&v_x<=max(x1,x2)&&min(y1,y2)<=v_y&&v_y<=max(y1,y2)){//(v_x,v_y)は線分の中にある
            //cout<<"a ";
            return distance_between_the_two_pointss(p_x, p_y, v_x, v_y);
        }else{//(v_x,v_y)は線分の外にある
            double l1 = distance_between_the_two_pointss(p_x, p_y, x1, y1);
            double l2 = distance_between_the_two_pointss(p_x, p_y, x2, y2);
            //cout<<"b ";
            return min(l1,l2);
        }
    }else{
        if(min(x1,x2)<=p_x&&p_x<=max(x1,x2)&&min(y1,y2)<=p_y&&p_y<=max(y1,y2)){//(p_x,p_y)は線分の中にある
            //cout<<"c ";
            return 0.0;
        }else{//(p_x,p_y)は線分の外にある
            double l1 = distance_between_the_two_pointss(p_x, p_y, x1, y1);
            double l2 = distance_between_the_two_pointss(p_x, p_y, x2, y2);
            //cout<<"d ";
            return min(l1,l2);
        }
    }
    
}


int main(){
    int n;
    while(cin>>n){
        if(n==0)break;
        double w[100][3];
        for(int i=0; i<n; i++){
            cin>>w[i][0]>>w[i][1]>>w[i][2];
        }
        
        int m;
        cin>>m;
        double t_x, t_y, o_x, o_y;
        
        for(int i=0; i<m; i++){
            cin>>t_x>>t_y>>o_x>>o_y;
            bool flag=true;
            for(int j=0; j<n; j++){
                double t_e=distance_between_the_two_pointss(t_x, t_y, w[j][0], w[j][1]);
                double o_e=distance_between_the_two_pointss(o_x, o_y, w[j][0], w[j][1]);

                
                
                if(t_e<w[j][2]&&o_e<w[j][2]){//太郎と鬼が円の中
                    
                }else if(t_e<w[j][2]||o_e<w[j][2]){//太郎か鬼のどちらかが円の中
                    cout<<"Safe"<<endl;
                    flag=false;
                    break;
                }else{//太郎と鬼が円の外
                    if(distance_between_the_line_segment_and_point(w[j][0], w[j][1], t_x, t_y, o_x, o_y)<=w[j][2]){
                        cout<<"Safe"<<endl;
                        flag=false;
                        break;
                    }
                    
                }
            }
            if(flag)cout<<"Danger"<<endl;
            
        }
        
    }
}
