def InsertionSort(L):
    if(len(L)<1):
        return L 
    for i in range(len(L)):
        #assume L[:i] is sorted.
        j=i
        #insert the ith number to its correct position in 0 to i-1.
        while(j>0 and L[j-1]>L[j]):
            L[j],L[j-1]=L[j-1],L[j]

            j=j-1
        #Now L[:i+1] is sorted.

    return L 

print(InsertionSort([2,3,1,4,5,0,5,2,8]))

