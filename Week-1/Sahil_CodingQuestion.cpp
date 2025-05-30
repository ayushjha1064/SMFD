#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
vector<long long> catalan_numbers(int n) {
 vector<long long> cat(n+1, 0);
 cat[0] = 1;
 for (int i = 1; i <= n; ++i) {
 for (int j = 0; j < i; ++j) {
 cat[i] = (cat[i] + cat[j] * cat[i-j-1]) % MOD;//we had to take inverse modulus here
 }
 }
 return cat;
}
int32_t main() {
 int n = 100;
 vector<long long> cat = catalan_numbers(n);//iterateive soln for al 100
 //we are precomputing all the values
 for (int i = 1; i <= n; ++i) {
 cout << cat[i] << " ";
 }
 cout << endl;
 return 0;
}
//for time complexity its O(n) as we are taking modulus so space is almost constant
//but for calculating catlan number in general it will be worst as the multiplication
//dosnt take constant time it takes somthing in order of log
