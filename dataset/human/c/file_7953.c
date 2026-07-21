#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  int n, k, c, i, tmp, cou=0, j;
  char ox;
  scanf(" %d %d %d", &n, &k, &c);
  int s[n], p[n], pt[n], p2[n]; //ox, 労働確定日か, pの仮定, どこから労働確定日でないと分かっているか
  for(i=0; i < n; i++){
    scanf(" %c", &ox);
    if(ox == 'o') s[i]=0;
    else s[i]=1;
  }

  /*******************************************************/
  //規定回数より多く働けるなら確定日無し
  for(i=0; i < n; i++){
    if(s[i] == 1){
      continue;
    } //労働不可の日はスキップ
    tmp=0; //tmp日目
    for(j=i; j < n; j++){
      if(s[j] == 1) continue;
      tmp=j;
      cou++;
      break;
    }

    while(tmp < n){
      tmp+=c + 1;
      while(tmp < n && s[tmp] == 1)
        tmp++;
      if(tmp < n) cou++;
      if(cou > k) return 0; //規定回数より多く働けるなら確定日無し
    }
    break; //そうでなければ通常通り
  }
  /*******************************************************/

  ////前から予定を詰めていく////
  memcpy(p, s, sizeof(s));
  memcpy(pt, p, sizeof(p));

  for(i=0; i < n; i++){
    if(p[i] == 1){
      //  printf("XXcontinueXX i=%d\n", i);
      continue;
    } //労働不可の日はスキップ
    tmp=0; //tmp日目
    cou=0;
    //s[i]=1; //労働不可と仮定

    for(j=0; j < n; j++)
      p[j]=1;
    for(j=0; j < n; j++){
      if(s[j] == 1){
        //    printf("--continue-- i=%d\n\n", i);
        continue;
      }
      tmp=j;
      p[j]=0;
      cou++;
      break;
    }

    while(tmp < n){
      tmp+=c + 1;
      while(tmp < n && s[tmp] == 1)
        tmp++;
      if(tmp < n){
        cou++;
        p[tmp]=0;
      }
      if(cou >= k) break; //成立可能
    }
/*
    printf("i=%d\n", i);
    for(j=0; j < n; ++j)
      printf("%d", s[j]);
    printf("  <=s   j=%d  cou=%d\n", n, cou);
    for(j=0; j < n; ++j)
      printf("%d", p[j]);
    printf("  <=p   j=%d  tmp=%d\n", n, tmp);
    for(j=0; j < n; ++j)
      printf("%d", pt[j]);
    printf("  <=pt  j=%d   \n", n);
*/
//    for(j=i; j <= tmp; ++j)
//      p[j]=p[j] | pt[j];
    for(j=tmp+1; j < n; ++j)
      p[j]=1;

 //   for(j=0; j < n; ++j)
 //     printf("%d", p[j]);
 //   printf("  <=p\n\n");
  //  printf("  tmp:%d\n\n",tmp);
    break;
  }


  ////後ろから予定を詰めていく////

  memcpy(p2, s, sizeof(s));
  memcpy(pt, p2, sizeof(p2));

  for(i=0; i < n; i++){
    if(p2[n - i - 1] == 1){
      //  printf("XXcontinueXX i=%d\n", i);
      continue;
    } //労働不可の日はスキップ
    tmp=n - 1; //tmp日目
    cou=0;
    //s[i]=1; //労働不可と仮定

    for(j=0; j < n; j++)
      p2[n - j - 1]=1;
    for(j=0; j < n; j++){
      if(s[n - j - 1] == 1){
        //    printf("--continue-- i=%d\n\n", i);
        continue;
      }
      tmp=n - j - 1;
      p2[n - j - 1]=0;
      cou++;
      break;
    }

    while(tmp >= 0){
      tmp-=c + 1;
      while(tmp >= 0 && s[tmp] == 1)
        tmp--;
      if(tmp >= 0){
        cou++;
        p2[tmp]=0;

      }
      if(cou >= k) break; //労働不可で成立可能なら労働確定日でない
    }
/*
    printf("i=%d\n", i);
    for(j=0; j < n; ++j)
      printf("%d", s[j]);
    printf("  <=s   j=%d  cou=%d\n", n, cou);
    for(j=0; j < n; ++j)
      printf("%d", p2[j]);
    printf("  <=p2  j=%d  tmp=%d\n", n, tmp);
    for(j=0; j < n; ++j)
      printf("%d", p2[j]);
    printf("  <=p2  j=%d\n", n);
*/
//    for(j=i; j <= n - tmp; ++j)
//      p2[j]=p2[j] | pt[j];
    for(j=n-tmp+1; j < n; ++j)
      p2[j]=1;

//   for(j=0; j < n; ++j)
//      printf("%d", p2[j]);
//    printf("  <=p2\n\n");
    break;
  }

  for(i=0; i < n; i++)
    if((p[i] | p2[i]) == 0) printf("%d\n", i+1);

}
