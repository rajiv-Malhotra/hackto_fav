#include <bits/stdc++.h>
using namespace std;
void sieve(int num) {
   bool p[num+1];
   memset(p, true, sizeof(p));
   for (int i=2;i*i<=num;i++) {
      if (p[i]==true) {
         for (int j = i*2; j<=num; j+=i)
         p[j] = false;
      }
   }
   for (int i = 2; i<=num; i++)
   if (p[i])
   cout << i << " ";
}
int main() {
   int num;
   cin>>num;
   cout << "The prime numbers less than equal to "<< num <<" are: ";
   sieve(num);
   return 0;
}

//Sample input - 43
//Sample output - The prime numbers less than equal to 43 are: 2 3 5 7 11 13 17 19 23 29 31 37 41 43