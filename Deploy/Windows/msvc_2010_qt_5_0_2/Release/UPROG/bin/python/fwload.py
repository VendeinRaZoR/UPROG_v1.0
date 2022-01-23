import sys

fwformat = str("Bytestream/Intel HEX (*.hex);;MCS-86 (*.mcs)")

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
def symblistpair(symblist):
    return [symblist[i] + symblist[i+1] for i in xrange(0,len(symblist),2) if i < len(symblist)-1]

def fwload(fwfilename):
    offset = 0
    hexlist = []
    print fwfilename
    #print fwfilename.decode('utf-8')
    fwfile = open(fwfilename.decode('utf-8'))
    if(fwfilename[-4:] == ".hex" or fwfilename[-4:] == ".mcs"):
        emptyfile = fwfile.read(1)
        if(emptyfile != '' and emptyfile != None):
            fwfile.seek(0)
            if(fwfile.read(1) == ':'):
                fwfile.seek(0)
                for fwrecnum,fwrec in enumerate(fwfile):
                    if(fwrec[0] != ':'):
                        fwfile.close()
                        return [ HEXFileError.BEGRECERR, fwrecnum ]  
                    fwrecstr = list(fwrec)
                    fwrecstr.pop(0)
                    fwrecstr = symblistpair(fwrecstr)
                    fwrecint = [int(irec,16) for irec in fwrecstr]
                    fwchecksum = fwrecint.pop()
                    checksum = 1 + ~(sum(fwrecint) & 0xFF) & 0xFF
                    if(checksum == fwchecksum): 
                        if(fwrecint[3] == HEXRecordType.DATA):
                            for i in range(1,fwrecint[0]+1):
                                hexlist.append(fwrecint[3+i])
                        elif(fwrecint[3] == HEXRecordType.EOF):
                            fwfile.close()
                            return hexlist
                        elif(fwrecint[3] == HEXRecordType.ADDRSEG):
                            offset = int(fwrecstr[4] + fwrecstr[5],16)
                        elif(fwrecint[3] == HEXRecordType.ADDREX):
                            offset = int(fwrecstr[5] + '0000',16)
                        else:
                            fwfile.close()
                            return [ HEXFileError.RECTYPEERR, fwrecnum ]
                    else:
                        fwfile.close()
                        return [ HEXFileError.CSUMERR, fwrecnum ]                     
            else:               #this is ByteStream HEX Format
                fwfile.seek(0)
                for fwrecnum,fwrec in enumerate(fwfile):
                    hexlist = symblistpair(fwrec)
                    hexlist = [int(i,16) for i in hexlist]
    fwfile.close()
    return hexlist
