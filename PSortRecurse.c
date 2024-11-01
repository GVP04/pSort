//Recursive sorting. Best for heavy in comparision and heavy copying data
using SorDataType = int;

int PSortRecurse(int nItems, SorDataType* ArrToSort, SorDataType*** idx1, SorDataType*** idx2)
{
    if (nItems > 0 && ArrToSort)
    {
        if (nItems > 3)
        {
            int nItems1 = (nItems + 1) / 2; //nItems1 >= nItems -  nItems1
            SorDataType** idx2_1 = *idx1 + nItems1;
            SorDataType** idx2_2 = *idx2 + nItems1;

            PSortRecurse(nItems1, ArrToSort, idx1, idx2);

            PSortRecurse(nItems - nItems1, ArrToSort + nItems1, &idx2_1, &idx2_2);

            register SorDataType** curIdx1 = *idx2;
            register SorDataType** curIdx2 = idx2_2;
            SorDataType** stopIdx1 = curIdx1 + nItems1;
            SorDataType** stopIdx2 = curIdx2 + nItems -nItems1;
            register SorDataType** destIdx = *idx1;
            SorDataType** stopdestIdx = destIdx + nItems;
            
            while (destIdx < stopdestIdx)
            {
                while (curIdx1 < stopIdx1 && curIdx2 < stopIdx2)
                    if ( **curIdx1 < **curIdx2)
                        *destIdx++ = *curIdx1++;
                    else 
                        *destIdx++ = *curIdx2++;

                while (curIdx1 < stopIdx1)
                    *destIdx++ = *curIdx1++;
                while (curIdx2 < stopIdx2)
                    *destIdx++ = *curIdx2++;
            }

            int** tmpSwap = *idx1;
            *idx1 = *idx2;
            *idx2 = tmpSwap;
        }
        else if (nItems == 3)
        {
            if (ArrToSort[0] < ArrToSort[1])
            {
                if (ArrToSort[0] < ArrToSort[2])
                {
                    if (ArrToSort[1] < ArrToSort[2])
                    {
                        (*idx2)[0] = ArrToSort;
                        (*idx2)[1] = ArrToSort + 1;
                        (*idx2)[2] = ArrToSort + 2;
                    }
                    else 
                    {
                        (*idx2)[0] = ArrToSort;
                        (*idx2)[1] = ArrToSort + 2;
                        (*idx2)[2] = ArrToSort + 1;
                    }
                }
                else
                {
                    (*idx2)[0] = ArrToSort + 2;
                    (*idx2)[1] = ArrToSort;
                    (*idx2)[2] = ArrToSort + 1;
                }
            }
            else
            {
                if (ArrToSort[0] < ArrToSort[2])
                {
                    (*idx2)[0] = ArrToSort + 1;
                    (*idx2)[1] = ArrToSort;
                    (*idx2)[2] = ArrToSort + 2;
                }
                else
                {
                    if (ArrToSort[1] < ArrToSort[2])
                    {
                        (*idx2)[0] = ArrToSort + 1;
                        (*idx2)[1] = ArrToSort + 2;
                        (*idx2)[2] = ArrToSort;
                    }
                    else 
                    {
                        (*idx2)[0] = ArrToSort + 2;
                        (*idx2)[1] = ArrToSort + 1;
                        (*idx2)[2] = ArrToSort;
                    }
                }
            }
        }
        else if (nItems == 2)
        {
            if (ArrToSort[0] < ArrToSort[1])
            {
                (*idx2)[0] = ArrToSort;
                (*idx2)[1] = ArrToSort+1;
            }
            else
            {
                (*idx2)[0] = ArrToSort + 1;
                (*idx2)[1] = ArrToSort;
            }
        }
        else 
            (*idx2)[0] = ArrToSort;

    }
    return 0;
}

int PSortRecurse(int nItems, SorDataType* ArrToSort, SorDataType** ArrIdx)
{
    if (nItems > 0 && ArrToSort)
    {
        SorDataType** idx1 = new SorDataType * [nItems];
        SorDataType** idx2 = new SorDataType * [nItems];

        PSortRecurse(nItems, ArrToSort, &idx1, &idx2);

        if (ArrIdx)
        {
            *ArrIdx = *idx2;
            delete[] idx1;
        }
        else
        {
            for (int i = 0; i < nItems; i++)
                if (idx2[i] != ArrToSort + i)
                {
                    register int curId = i;
                    SorDataType swapValue = ArrToSort[curId];
                    int swapIndex = curId;
                    register int nextId;

                    do
                    {
                        nextId = idx2[curId] - ArrToSort;
                        ArrToSort[curId] = ArrToSort[nextId];

                        idx2[curId] = ArrToSort + curId;
                        curId = nextId;
                    } while (idx2[nextId] != ArrToSort + swapIndex);

                    ArrToSort[nextId] = swapValue;
                    idx2[nextId] = ArrToSort + nextId;
                }

            delete[] idx1;
            delete[] idx2;
        }
    }

    return 0;
}
