# RSA and Arithmetic of large numbers
RSA的C++实现，包括大数运算的实现

## 命令行：
<code>RSA -g generateFilePath</code>
生成公钥和私钥

<code>RSA -p plainfile -n nfile [-e efile] [-d dfile] -c cipherfile</code>

#### 参数说明
    -p plainfile        指定明文文件的位置和名称 
    -n nfile            指定存放整数n的文件的位置和名称 
    -e efile            在数据加密时，指定存放整数e的文件的位置和名称 
    -d dfile            在数据解密时，指定存放整数d的文件的位置和名称 
    -c cipherfile       指定密文文件的位置和名称 

