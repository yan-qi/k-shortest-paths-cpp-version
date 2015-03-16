# An implementation of K-Shortest Path Algorithm (Cpp Version)

The description of the original algorithm could be found in the paper, 'A New Implementation Of Yen's Ranking Loopless Paths Algorithm' (http://citeseer.ist.psu.edu/martins00new.html).

##Introduction
Yen’s algorithm is one of derivation algorithms for ranking the K shortest paths between a pair of nodes[1]. It always searches the shortest paths in a “pseudo”-tree containing K shortest loopless paths. The very shortest one is obtained in the first place, and the second shortest path is always explored on the basis of the shortest paths that are shorter. In our paper, we exploit the implementation of Yen’s algorithm in [1]. Compared with the straightforward implementation of Yen’s algorithm, the one present in [1] is proved to have a better performance in computational experiments, although the complexity of them are the same, O(Kn(m+nlogn)) in the worst case analysis.

##Implementation

The package contains the implementation of Yen's algorithm for top-k shortest paths in a directed weighted graph. 

Note that:

1. It's implemented in CPP. (The version is 2)
2. The source code is compiled under visual studio 2008 c/c++ compiler. 
3. Compared with previous versions, version 2 does not require Boost library any longer.
4. Main() function explains how to use the implentation. 

##Update

* A checking is added in the C++ implementation to make sure the number of vertices in the input file is correct. 
* The C++ version of the algorithm is ready for downloading. This implementation follows the similar design as its [Java counterpart]().* A bug is fixed in the Java implementation. The algorithm presented in Reference [1] is not always right. Specifically, the test case with the graph (see 'test_6_1' in the source package) can not return all results if the algorithm is applied. 
* A fix on the comparator associated with Class QYDirectedPath is provided for the CPP implementation. Thanks a lot to timothyahahn. 
* The implementation of top-k shortest path algorithm in *C#* by Vinh Bui (vinhqb@gmail.com) is added. Note that I won't test this code completely. 

##Reference

[1]: M. Pascoal and E. Martins. A new implementation of Yen’s ranking loopless paths algorithm. 4OR – Quarterly Journal of the Belgian, French and Italian Operations Research Societies, 2003.

[2]: A Fortran implementation: http://www.mat.uc.pt/~eqvm/OPP/KSPP/KSPP.html.