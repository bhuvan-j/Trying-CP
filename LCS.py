#   LCS

L=[9,1,8,6,3,4,2,7,10,15]
d={}
for i in L:
    d[i]=True
gen_start=-1
length=0
for i in L:
    if d[i]:
        next=i+1
        prev=i-1
        count=1
        start=i
        while next in d.keys():
            count+=1
            d[next]=False
            next+=1
        while prev in d.keys():
            count+=1
            start=prev
            d[prev]=False
            prev-=1
        #print(start,count)
        length=max(length,count)
        #print("now length is:",length)
        gen_start=start if length==count else gen_start
        #print("now start is:",gen_start)
#print(gen_start,length)
print("the LCS is:")
while(length):
    print(gen_start,end=' ')
    gen_start+=1
    length-=1
        