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
27o:
	clang++ problem027.cpp primes.cpp -fopenmp -o prod/problem027-omp
	time ./prod/problem027-omp