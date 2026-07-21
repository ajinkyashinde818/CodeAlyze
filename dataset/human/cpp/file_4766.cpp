//
//  main.cpp
//  ProgrammingContestChallengeBook2
//
//  Created by Hisaki Kobayashi on 2020/04/04.
//  Copyright © 2020 Hisaki Kobayashi. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
//#include "mylibrary.hpp"



using namespace std;

int main(){
    int N,R;
    cin >> N >> R;
    int ANS;
    if(N>=10){
        ANS = R;
    }else{
        ANS = R+100*(10-N);
    }
    cout << ANS << endl;
    return 0;
 
}
