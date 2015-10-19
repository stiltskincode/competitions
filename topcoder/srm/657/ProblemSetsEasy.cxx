#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class ProblemSetsEasy {
public:
	int maxSets(int, int, int, int, int);
};

int ProblemSetsEasy::maxSets(int E, int EM, int M, int MH, int H) {
	while (1)
	{
		if (!EM && !MH){
			return min(E, min(M, H));
		}
		else if (!MH){
			if (E > M){
				M++;
				EM--;
			}
			else {
				E++;
				EM--;
			}
		}
		else if (!EM){
			if (H > M){
				M++;
				MH--;
			}
			else{
				H++;
				MH--;
			}
		}
		else {
			if (E < H){
				if (E > M){
					M++;
					EM--;
				}
				else{
					E++;
					EM--;
				}
			}
			else if (E > H){
				if (M > H){
					MH--;
					H++;
				}
				else if (M < H){
					MH--;
					M++;
				}
				else{
					MH--;
					M++;
				}
			}
			else{
				 if (EM < MH){
					E++;
					EM--;
				}
				else{
					EM--;
					M++;
				}
			}

		}
	}
}
