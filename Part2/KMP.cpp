#include <iostream>
#include <vector>

#define endl '\n'

std :: vector <int> Get_Next (std :: string S) {
	
	int N = S.length ();
	
	std :: vector <int> Result;
	
	Result.push_back (0);
	
	for (int i = 1, j = 0; i < N; ++ i) {
		
		while (j > 0 and S[i] != S[j]) {
			
			j = Result[j - 1];
		}
		
		if (S[i] == S[j]) {
			
			++ j;
		}
		
		Result.push_back (j);
	}
	
	return Result;
}

std :: vector <int> KMP (std :: string S, std :: string T, std :: vector <int> Next) {
	
	int N = S.length (), M = T.length ();
	
	std :: vector <int> Result;
	
	for (int i = 0, j = 0; i < N; ++ i) {
		
		while (j > 0 and S[i] != T[j]) {
			
			j = Next[j - 1];
		}
		
		if (S[i] == T[j]) {
			
			++ j;
		}
		
		if (j == M) {
			
			Result.push_back (i - M + 2);
			
			j = Next[j - 1];
		}
	}
	
	return Result;
}

int main (void) {
	
	std :: ios :: sync_with_stdio (false);
	std :: cin.tie (nullptr);
	std :: cout.tie (nullptr);
	
	std :: string S, T;
	
	std :: cin >> S >> T;
	
	std :: vector <int> Next = Get_Next (T);
	std :: vector <int> Result = KMP (S, T, Next);
	
	for (int i : Result) {
		
		std :: cout << i << endl;
	}
	
	for (int i : Next) {
		
		std :: cout << i << ' ';
	}
	
	return 0;
}