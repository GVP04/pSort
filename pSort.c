int _PSort(int nItems, int* ArrToSort, int** ArrIdx)
{
    if (nItems > 0 && ArrToSort)
    {
        int* idx1 = new int[nItems];
        int* idx2 = new int[nItems];

        //initial step
        int i, k;

        for (i = 0, k = 1; k < nItems; i++, k++)
            if (ArrToSort[i] < ArrToSort[k])
            {
                idx1[i] = i++;
                idx1[k] = k++;
            }
            else
            {
                idx1[i] = k;
                idx1[k++] = i++;
            }

        if (i < nItems)  idx1[i] = i;

        //main step
        int* swapIdx1 = idx1;
        int* swapIdx2 = idx2;

        for (i = 2; i < nItems; i *= 2)
        {
            int dblI = i + i;
            int* curIdx1 = swapIdx1;
            int* curIdx2 = swapIdx1 + i;
            int* MaxIdx = swapIdx1 + nItems;
            int* stopIdx1 = curIdx1 + i;
            int* stopIdx2 = curIdx2 + i;
            int* destIdx = swapIdx2;
            int* stopdestIdx = destIdx + nItems;

            while (destIdx < stopdestIdx)
            {
                if (stopIdx1 > MaxIdx) stopIdx1 = MaxIdx;
                if (stopIdx2 > MaxIdx) stopIdx2 = MaxIdx;

                while (curIdx1 < stopIdx1 && curIdx2 < stopIdx2)
                {
                    if (ArrToSort[*curIdx1] < ArrToSort[*curIdx2])
                        *(destIdx++) = *(curIdx1++);
                    else
                        *(destIdx++) = *(curIdx2++);
                }

                while (curIdx1 < stopIdx1)
                    *(destIdx++) = *(curIdx1++);

                while (curIdx2 < stopIdx2)
                    *(destIdx++) = *(curIdx2++);

                curIdx1 += i;
                curIdx2 += i;
                stopIdx1 += dblI;
                stopIdx2 += dblI;
            }

            int* tmpSwap = swapIdx1;
            swapIdx1 = swapIdx2;
            swapIdx2 = tmpSwap;
        }

        if (ArrIdx)
        {
            *ArrIdx = swapIdx1;
            delete[] swapIdx2;
        }
        else
        {
            for (i = 0; i < nItems; i++)
                if (swapIdx1[i] != i)
                {
                    int curId = i;
                    int swapValue = ArrToSort[curId];
                    int swapIndex = curId;
                    int nextId = swapIdx1[curId];

                    do
                    {
                        nextId = swapIdx1[curId];
                        ArrToSort[curId] = ArrToSort[nextId];

                        swapIdx1[curId] = curId;
                        curId = nextId;

                    } while (swapIdx1[nextId] != swapIndex);

                    ArrToSort[nextId] = swapValue;
                    swapIdx1[nextId] = nextId;
                }

            delete[] idx1;
            delete[] idx2;
        }
    }

    return 0;
}
