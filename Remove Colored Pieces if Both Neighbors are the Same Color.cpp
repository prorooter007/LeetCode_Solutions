#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool winnerOfGame(string str) {
          int alice = 0, bob = 0;

        int A = 0, B = 0;

        for(int i = 0; i < str.length(); i++) {
            if(str[i] == 'A') {
                A++;
                bob += max(0, B - 2);
                B = 0;
            }
            else {
                B++;
                alice += max(0, A - 2);
                A = 0;
            }
        }

        alice += max(0, A - 2);
        bob += max(0, B - 2);


        if(alice == 0) return false;

        if(alice > bob) return true;

        return false;
    }
};