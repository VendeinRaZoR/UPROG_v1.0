import sys

fwFormat = str("Bytestream/Intel HEX (*.hex);;MCS-86 (*.mcs)")

class HEXFileError(object):
    BEGRECERR = -1
    RECTYPEERR = -2
    CSUMERR = -3

class HEXRecordType(object):
    DATA = 0
    EOF = 1
    ADDRSEG = 2
    ADDREX = 4

#from list of chars to list of bytes in string format
def symbListPair(symbList):
    return [symbList[i] + symbList[i+1] for i in xrange(0,len(symbList),2) if i < len(symbList)-1]

def fwLoad(fwFileName):
    offset = 0
    hexList = []
    print fwFileName
    #print fwfilename.decode('utf-8')
    fwFile = open(fwFileName.decode('utf-8'))
    if(fwFileName[-4:] == ".hex" or fwFileName[-4:] == ".mcs"):
        emptyfile = fwFile.read(1)
        if(emptyfile != '' and emptyfile != None):
            fwFile.seek(0)
            if(fwFile.read(1) == ':'):
                fwFile.seek(0)
                for fwRecNum,fwRec in enumerate(fwFile):
                    if(fwRec[0] != ':'):
                        fwFile.close()
                        return [ HEXFileError.BEGRECERR, fwRecNum ]  
                    fwRecStr = list(fwRec)
                    fwRecStr.pop(0)
                    fwRecStr = symbListPair(fwRecStr)
                    fwRecInt = [int(iRec,16) for iRec in fwRecStr]
                    fwCheckSum = fwRecInt.pop()
                    checkSum = 1 + ~(sum(fwRecInt) & 0xFF) & 0xFF
                    if(checkSum == fwCheckSum): 
                        if(fwRecInt[3] == HEXRecordType.DATA):
                            for i in range(1,fwRecInt[0]+1):
                                hexList.append(fwRecInt[3+i])
                        elif(fwRecInt[3] == HEXRecordType.EOF):
                            fwFile.close()
                            return hexList
                        elif(fwRecInt[3] == HEXRecordType.ADDRSEG):
                            offset = int(fwRecStr[4] + fwRecStr[5],16)
                        elif(fwRecInt[3] == HEXRecordType.ADDREX):
                            offset = int(fwRecStr[5] + '0000',16)
                        else:
                            fwFile.close()
                            return [ HEXFileError.RECTYPEERR, fwRecNum ]
                    else:
                        fwFile.close()
                        return [ HEXFileError.CSUMERR, fwRecNum ]                     
            else:               #this is ByteStream HEX Format
                fwFile.seek(0)
                for fwRecNum,fwRec in enumerate(fwFile):
                    hexList = symbListPair(fwRec)
                    hexList = [int(i,16) for i in hexList]
    fwFile.close()
    return hexList
