#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include "RSA.h"

using namespace std;

string getValueByPara(string key, int argc, char * argv[]) {

    for(int i = 0; i < argc; i++) {
        if(key == argv[i])
            return argv[i+1];
    }
    return "";

}

bool hasPara(string key, int argc, char * argv[]) {
    for(int i = 0; i < argc; i++) {
        if(key == argv[i])
            return true;
    }
    return false;
}

int main(int argc, char * argv[]) {

    ifstream nFile;
    ifstream eFile;
    ifstream dFile;
    ifstream plainFileInstream;
    ofstream plainFileOutstream;
    ifstream cipherFileInstream;
    ofstream cipherFileOutstream;

    string n,e,d,plain,cipher;

    RSA rsa;

    string cipherFromPlain;
    string plainFromCipher;

    if(hasPara("-g",argc,argv)) {
        rsa.generateKey(getValueByPara("-g", argc, argv));
        cout<<"Relevant files has been generated. \nIncludes: p.txt, q.txt, n.txt, e.txt, d.txt"<<endl;
        cout<<"And two description file: rsa_public.txt rsa_private.txt"<<endl;
        ofstream pubkey;
        ofstream prikey;
        pubkey.open(getValueByPara("-g", argc, argv) + "rsa_public.txt");
        pubkey<<("n=" + rsa.getN() + "\n");
        pubkey<<("e=" + rsa.getE() + "\n");

        prikey.open(getValueByPara("-g", argc, argv) + "rsa_private.txt");
        prikey<<("n=" + rsa.getN() + "\n");
        prikey<<("d=" + rsa.getD() + "\n");
    }


    if(hasPara("-n",argc,argv)) {
        nFile.open(getValueByPara("-n", argc, argv));
        nFile>>n;
    }

    if(hasPara("-e",argc,argv)) {
        eFile.open(getValueByPara("-e", argc, argv));
        plainFileInstream.open(getValueByPara("-p", argc, argv));
        plainFileInstream>>plain;
        eFile>>e;
        rsa.setPublicKey(n,e);
        cipherFromPlain = rsa.encrypt(plain);
        cipherFileOutstream.open(getValueByPara("-c", argc, argv));
        cipherFileOutstream<<cipherFromPlain;

        //打印提示信息
        cout<<"Encrypt success."<<endl;
        string hint = "The Cipher file is at \"";
        hint += getValueByPara("-c", argc, argv);
        hint += "\"";
        cout<<hint<<endl;

    }
    if(hasPara("-d",argc,argv)) {
        dFile.open(getValueByPara("-d", argc, argv));
        cipherFileInstream.open(getValueByPara("-c", argc, argv));
        cipherFileInstream>>cipher;
        dFile>>d;
        rsa.setPrivateKey(n,d);
        plainFromCipher = rsa.decrypt(cipher);
        plainFileOutstream.open(getValueByPara("-p", argc, argv));
        plainFileOutstream<<plainFromCipher;

        //打印提示信息
        cout<<"Decrypt success."<<endl;
        string hint = "The Plaintext file is at \"";
        hint += getValueByPara("-p", argc, argv);
        hint += "\"";
        cout<<hint<<endl;
    }




    return 0;
}