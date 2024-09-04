pSort created for sorting strings, objects etc

Better then qSort  (qSort/pSort):
  by comparision ~ 1.5 
  by copy values >= Log2(N)  

Easyly transforms to template

Amount of value comparisions (N>4):   
MIN = N/2 * Log2(N)   - in case full sorted array
MAX = N*Log2(N) - N   - in case reverse full sorted array

Amount of copy values < N + Log2(N)

For random array with 100000000 (100M) elements:
                        _100000000                      _100000000                      _100000000                      _100000000
        PSORT   nCmp =  2128475998      nCmpIdx =       5028476014      nCopyIdx =      3000000114      nCopyValue =     100000018      nMaxRec =       0       
        QSORT   nCmp =  3257683836      nCmpIdx =       3435769678      nCopyIdx =      1056595834      nCopyValue =    1406807909      nMaxRec =       58      
                        ^  ^  ^  ^                      ^  ^  ^  ^                      ^  ^  ^  ^                      ^  ^  ^  ^                                
        
Not good with memory, but wins with heavy comparision or complex data
Needs 2 * N * sizeof(int) aditional memory
Recurrences not used, but is possible

Two modes 
 1 create index array
 2 real sorting

int _PSort(int nItems, int* ArrToSort, int** ArrIdx)

if ArrIdx is not NULL - creates IDX array. In other case sorts ArrToSort


Example:

Steps:
1 sort idx as pairs - 1,2 3,4 ......
2...i = 4 to n/log2(n)  sort idx as pair of sorted arrays - 1,2,3,4  4,6,7,8, ...... n/i <-> n/i + i   where i = 2^nIteration
3 [real sort]

--------- Initial data ----------
ArrToSort   	2	5	8	9	11	3	2	1	7
(virtual idx)	0	1	2	3	4	5	6	7	8
---------------------------------

Step1: 		order 0 1	order 2 3	order 4 5	order 6 7	order 8   idx2 ->>> idx1
ArrToSort   	2	5	8	9	11	3	2	1	7
ArrIdx1		0	1	2	3	5	4	7	6	8
ArrIdx2		NA	NA	NA	NA	NA	NA	NA	NA	NA


Step2.1:  	order 0 1 & 2 3			order 4 5 & 6 7			order 8   idx1 ->>> idx2
ArrToSort   	2	5	8	9	11	3	2	1	7
ArrIdx1		0	1	2	3	5	4	7	6	8
ArrIdx2		0	1	2	3	7	6	5	4	8


Step2.2:  	order 0 1 2 3	&   4 5 6 7					order 8   idx2 ->>> idx1
ArrToSort   	2	5	8	9	11	3	2	1	7
ArrIdx1		7	0	6	5	1	2	3	4	8
ArrIdx2		0	1	2	3	7	6	5	4	8


Step2.2:  	order 0 1 2 3 4 5 6 7	&  8   						idx1 ->>> idx2
ArrToSort   	2	5	8	9	11	3	2	1	7
ArrIdx1		7	0	6	5	1	2	3	4	8
ArrIdx2		7	0	6	5	1	8	2	3	4	


Step3: (if need)  SORT ArrToSort   by idx2
ArrToSort   	1	2	2	3	5	7	8	9	11	
ArrIdx1		7	0	6	5	1	2	3	4	8
ArrIdx2		0	1	8	2	3	7	6	5	4











!!!!!!!!!!!!!!!!!!!!!!!!!!!! Need help with English. Please
