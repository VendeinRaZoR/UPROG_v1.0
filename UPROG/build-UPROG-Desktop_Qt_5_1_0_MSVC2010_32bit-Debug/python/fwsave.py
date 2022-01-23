import sys

fwFormat = str("Intel HEX (*.hex)")

numOfBytes = 16
numOfBytesOffset = 2

def fwsave(fwFileName,hexList):
    fwFile = open(fwFileName,'w')
    address = 0
    paragraph = 0
    checkSum = 1 + ~((numOfBytesOffset + 4) & 0xFF) & 0xFF
    offset = ':' + '{:02x}'.format(numOfBytesOffset).upper() + '{:04x}'.format(0).upper() + '{:02x}'.format(4).upper() + '{:04x}'.format(0).upper() + '{:02x}'.format(checkSum).upper() + '\n'
    fwfile.write(offset)
    for i,x in enumerate(hexList):
        if hexList[i] < 0:
            hexList[i] += 256
    for i in range(0,len(hexList),numOfBytes):
        if(i+numOfBytes > len(hexList)):
            hexList.extend([ 0 for i in range(len(hexList),i+numOfBytes) ])
            break
        checkSum = 1 + ~((sum(hexList[i:i+numOfBytes]) + numOfBytes + (address >> 8) + (address & 0x00FF)) & 0xFF) & 0xFF
        line = ':' + '{:02x}'.format(numOfBytes).upper() + '{:04x}'.format(address).upper() + '{:02x}'.format(0).upper() + "".join('{:02x}'.format(x) for x in hexList[i:i+numOfBytes]).upper() + '{:02x}'.format(checkSum).upper() + '\n'
        fwFile.write(line)
        address += numOfBytes
        if(address == 0x10000):
            address = 0
            paragraph += 1
            checkSum = 1 + ~((numOfBytesOffset + 4 + (paragraph >> 8) + (paragraph & 0x00FF)) & 0xFF) & 0xFF
            offset = ':' + '{:02x}'.format(numOfBytesOffset).upper() + '{:04x}'.format(0).upper() + '{:02x}'.format(4).upper() + '{:04x}'.format(paragraph).upper() + '{:02x}'.format(checkSum).upper() + '\n'
            fwFile.write(offset)
        #print line
    fwFile.write(":00000001FF")
    return
