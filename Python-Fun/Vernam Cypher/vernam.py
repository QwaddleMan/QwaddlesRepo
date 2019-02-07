#vernam.py
#@author Jason Bowerman
#this program will encrypt files using the vernam cypher algorithm
#which says the k^p=c c^k=p
#as of right now I am not handling errors, this is just to prove concept.

import array
#This function is the vernam cypher
#file is the file path for the file you want to encrypt
#key is the key that you are using to encrypt the file
def vernam(file, key):
    f = open(file,"rb")
    r = f.read()
    f.close()
    b = bytearray(r)
    for a in range(len(b)):
        b[a] = b[a]^ord(key[a%len(key)])#exclusive or each byte with a byte from the key
        print(str(a) + "/" + str(len(b)))
    
    return b

#get the key and the file path
path = input("enter a file path: ")
k = input("enter a key: ")
key = array.array('u',k)

#run the vernam cypher
result = vernam(path,key)
print("\n\n\n")

#return results as the file you inputed
res = open(path,"wb")
res.write(result)
res.close()
