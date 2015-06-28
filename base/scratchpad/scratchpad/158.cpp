#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable : 4996)
#pragma optimize( "", off )
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <iomanip> 
#include <map>
#include <algorithm>

using namespace std;

#define max(a,b) a>b ? a : b
#define min(a,b) a<b ? a : b
#define MAX_N 8
#define INF 1000000001
#define SIZE(x) ((x).size())
#define pb push_back
#define VAR(v, n) auto v = (n)
#define ALL(c) (c).begin(), (c).end()
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)

//std::copy(ALL(A), std::ostream_iterator<std::string>(std::cout, ", "));

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long long LL;

vector<LL> A;

void factorial(int n){
	int s = A.size();
	if (s ==0)
		A.pb(1);

	FOR(i, A.size(), n){
		LL x = A[i-1] * i;

		A.pb(x);
		//if (A[i] > 0x7FFFFFFF) break;
	}
}

int main()
{
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);


	string str1, str2;

	int n, k, idx, c;
	LL numer, denumer, res;

	while (true){

		std::getline(std::cin, str1);
		if (str1 == "#") break;
		if (str1.empty())
			cout << 1 << "\n";
		else{
			str2 = str1;
			sort(ALL(str2));

			map<char, int> K;

			vi P;

			K[str2[0]] = 0;
			P.pb(1);

			k = 0;

			n = str1.size();

			factorial(n);

			FOR(i, 1, str2.size() - 1){
				if (str2[i] != str2[i - 1]){
					K[str2[i]] = ++k;
					P.pb(1);
				}
				else
				{
					P[k]++;
				}
			}

			numer = res = 0;

			///dla kazdej literki (dla c)
			REP(i, n){

				idx = K[str1[i]];
				numer = A[n - i - 1];
				//iteruj po ich kolejnych mniejszych badz rownych liczbach (wez a i b)
				REP(j, idx){
					if (P[j]){
						denumer = 1;
						//zsumuj silnie kazdej literki oraz odejmij jeden od aktualnie przetwarzanej (dla a zbierz wszystkie do c minus 1 dla a)
						REP(l, P.size()){
							c = P[l];
							if (l == j) c--;
							denumer *= A[c];
						}

						res += numer / denumer;
					}
				}

				P[idx]--;
			}

			cout << res + 1 << "\n";

		}
	}
	return (0);
}