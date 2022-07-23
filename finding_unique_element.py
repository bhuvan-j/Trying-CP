##Find unique element
l=[2,2,3,3,4,4,5,5,7]

xor=0
for i in l:
    xor^=i
print(xor)

"""l.sort()
print(l)
for i in range(0,len(l)-1,2):
    if l[i]!=l[i+1]:
        print(l[i])
        break
print(l[-1])"""
