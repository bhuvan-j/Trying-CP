def SelectionSort(L):
    if(len(L)<1):
        return L 
    for i in range(len(L)):
        #assume L[:i] is sorted.
        mpos=i
        for j in range(i+1,len(L)):
            if(L[j]<L[mpos]):
                mpos=j
        L[i],L[mpos]=L[mpos],L[i]
        #Now L[:i+1] is sorted.
    return L 
  
  
