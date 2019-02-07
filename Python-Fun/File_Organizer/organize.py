from os import walk
import shutil


class Dir:
    def __init__(self,path,acc):
        self.path = path
        self.accRaw = acc
        self.acc = []
    def parseRawAcc(self):
        self.acc = self.accRaw.split(",")
        self.acc.remove('\n')
    def printVal(self,iteration):
        print(self.acc[iteration])
    def checkExt(self,ext):
        for r in self.acc:
            #print(r)
            #print(ext)
            if r == ext:
                return True
        return False


""" parse config data"""
confFile = open("files.conf","r")
confRaw = confFile.read()
confFile.close()
confRawArray = confRaw.split("-")
dirs = []
i = 0
while i < len(confRawArray):
    dirs.append(Dir(confRawArray[i],confRawArray[i+1]))
    i+=2
for part in dirs:
    part.parseRawAcc()
print(dirs[0].acc)


""" get all files """
allFiles = []
for (dirpath,dirnames,filenames) in walk(".\\"):
    allFiles.extend(filenames)
    break
print(len(allFiles))
print(allFiles)
for a in allFiles:
    t = a.split(".")
    if len(t) > 1:
        for b in dirs:
            if b.checkExt(t[1]) == True:
                shutil.move(a,b.path)
