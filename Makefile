1:
	clang++ problem001.cpp -o prod/problem001
	prod/problem001
2:
	clang++ problem002.cpp -o prod/problem002
	prod/problem002
3:
	clang++ problem003.cpp primes.cpp -o prod/problem003
	prod/problem003
4:
	clang++ problem004.cpp -o prod/problem004
	prod/problem004
5:
	clang++ problem005.cpp -o prod/problem005
	prod/problem005
6:
	clang++ problem006.cpp -o prod/problem006
	prod/problem006
7:
	clang++ problem007.cpp primes.cpp -o prod/problem007
	prod/problem007
8:
	clang++ problem008.cpp -o prod/problem008
	prod/problem008
9:
	clang++ problem009.cpp -o prod/problem009
	prod/problem009
10:
	clang++ problem010.cpp primes.cpp  -o prod/problem010
	prod/problem010
11:
	clang++ problem011.cpp -o prod/problem011
	prod/problem010
12:
	clang++ problem012.cpp -o prod/problem012
	prod/problem012
13:
	clang++ problem013.cpp -o prod/problem013
	prod/problem013
14:
	clang++ problem014.cpp -o prod/problem014
	prod/problem014
15:
	clang++ problem015.cpp -o prod/problem015
	prod/problem015
16:
	clang++ problem016.cpp -o prod/problem016
	prod/problem016
17:
	clang++ problem017.cpp -o prod/problem017
	prod/problem017
18:
	clang++ problem018.cpp -o prod/problem018
	prod/problem018
19:
	clang++ problem019.cpp -o prod/problem019
	./prod/problem019
23:
	clang++ problem023.cpp primes.cpp -o prod/problem023
	time ./prod/problem023
24:
	clang++ problem024.cpp -o prod/problem024
	./prod/problem024
27:
	clang++ problem027.cpp primes.cpp -o prod/problem027
	time ./prod/problem027

clean:
	rm -r problem???.dSYM
	rm -r prod
	rm -r cmake-build-debug