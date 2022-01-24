echo "/home/vendeinrazor/UPROG v1.0/UPROG/Deploy/Linux/GCC_x86_64/Debug/UPROG/bin/temp" | sudo tee -a /etc/ld.so.conf
sudo ldconfig > /etc/ld.so.conf
./UPROG 
