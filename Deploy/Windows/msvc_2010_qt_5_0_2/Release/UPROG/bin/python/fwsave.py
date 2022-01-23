import sys

fwformat = str("Intel HEX (*.hex)")

numOfBytes = 16
numOfBytesOffset = 2

startparagpaph = 0

def fwsave(fwfilename,hexlist):
    fwfile = open(fwfilename,'w')
    address = 0
    paragraph = 0
    checksum = 1 + ~((numOfBytesOffset + 4) & 0xFF) & 0xFF
    offset = ':' + '{:02x}'.format(numOfBytesOffset).upper() + '{:04x}'.format(0).upper() + '{:02x}'.format(4).upper() + '{:04x}'.format(0).upper() + '{:02x}'.format(checksum).upper() + '\n'
    fwfile.write(offset)
    for i,x in enumerate(hexlist):
        if hexlist[i] < 0:
            hexlist[i] += 256
    for i in range(0,len(hexlist),numOfBytes):
        if(i+numOfBytes > len(hexlist)):
            hexlist.extend([ 0 for i in range(len(hexlist),i+numOfBytes) ])
            break
        checksum = 1 + ~((sum(hexlist[i:i+numOfBytes]) + numOfBytes + (address >> 8) + (address & 0x00FF)) & 0xFF) & 0xFF
        line = ':' + '{:02x}'.format(numOfBytes).upper() + '{:04x}'.format(address).upper() + '{:02x}'.format(0).upper() + "".join('{:02x}'.format(x) for x in hexlist[i:i+numOfBytes]).upper() + '{:02x}'.format(checksum).upper() + '\n'
        fwfile.write(line)
        address += numOfBytes
        if(address == 0x10000):
            address = 0
            paragraph += 1
            checksum = 1 + ~((numOfBytesOffset + 4 + (paragraph >> 8) + (paragraph & 0x00FF)) & 0xFF) & 0xFF
            offset = ':' + '{:02x}'.format(numOfBytesOffset).upper() + '{:04x}'.format(0).upper() + '{:02x}'.format(4).upper() + '{:04x}'.format(paragraph).upper() + '{:02x}'.format(checksum).upper() + '\n'
            fwfile.write(offset)
        #print line
    fwfile.write(":00000001FF")
    return
