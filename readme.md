RSA and Arithmetic of large numbers

命令行格式：
RSA -g generateFilePath
用于生成公钥、私钥

RSA -p plainfile -n nfile [-e efile] [-d dfile] -c cipherfile 

-p plainfile        指定明文文件的位置和名称 
-n nfile            指定存放整数n的文件的位置和名称 
-e efile            在数据加密时，指定存放整数e的文件的位置和名称 
-d dfile            在数据解密时，指定存放整数d的文件的位置和名称 
-c cipherfile        指定密文文件的位置和名称 

