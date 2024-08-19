pSort created for sorting strings, objects etc
Amount of value comparisoins < N*Log2(N) - N. 
Amount of copy values < N + Log2(N)

For random array with 100 000 000 elements
        PSORT   nCmp =  2128475998      nCmpIdx =       5028476014      nCopyIdx =      3000000114      nCopyValue =    100000018       nMaxRec =       0       
        QSORT   nCmp =  3257683836      nCmpIdx =       3435769678      nCopyIdx =      1056595834      nCopyValue =    1406807909      nMaxRec =       58      
        
Not good with memory, but wins with heavy comparision or complex data
Needs 2 * N * sizeof(int) aditional memory
Recursion not used? but possible
Can be recurrences

Two modes 
 1 create index array
 2 real sorting

int _PSort(int nItems, int* ArrToSort, int** ArrIdx)

if ArrIdx is not NULL - creates IDX array. In other case sorts ArrToSort
