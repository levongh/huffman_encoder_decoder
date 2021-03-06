#include <string>
#include <cstring>

#include <queue>

#include "HuffmanTree.h"
#include "Decoder.h"

Decoder::Decoder(int argc, char** argv)
    : CoderBase(argc, argv)
{
}

unsigned char Decoder::readHuffmanChar(std::ifstream& infile) const
{
    static int pos = 0;
    static unsigned char ch = infile.get();
    unsigned char i;
    i = (ch >> (7 - pos)) % 2;
    ++pos;
    pos %= 8;
    if (pos == 0) {
        if (!infile.eof()) {
            ch = infile.get();
        } else {
            i = 2;
        }
    }
    return i;
}

void Decoder::decode() const
{
    std::ifstream  infile;
    std::ofstream outfile;
    openFileStreams(infile, outfile);

    unsigned int freq[256];
    char c;
    unsigned char ch;
    unsigned int j = 1;
    for (int idx = 0; idx < 256; ++idx) {
        freq[idx] = 0;
        for (int k = 3; k >= 0; --k) {
            infile.get(c);
            ch = c;
            freq[idx] += ch * (j << (8 * k));
        }
    }
    std::queue<Node*> nodes;
    for (unsigned idx = 0; idx < 256; ++idx) {
        if (freq[idx] > 0) {
            Node* tp = new Node;
            tp->setFreq(freq[idx]);
            tp->setChar(static_cast<unsigned char>(idx));
            nodes.push(tp);
        }
    }
    Node* tp = nullptr;
    Node* tp2 = nullptr;
    Node* tp3 = nullptr;
    do {
        tp = nodes.front();
        nodes.pop();
        if (!nodes.empty()) {
            tp2 = nodes.front();
            nodes.pop();
            tp3 = new Node;
            tp3->setFreq(tp->getFreq() + tp2->getFreq());
            tp3->setLeft(tp);
            tp3->setRight(tp2);
            nodes.push(tp3);
        }
    } while (!nodes.empty());

    HuffmanTree ht(tp);
    std::string str;
    unsigned char ch2;
    unsigned int total = ht.getRoot()->getFreq();
    while (total > 0) {
        str = "";
        do {
            ch = readHuffmanChar(infile);
            if (ch == 0) {
                str = str + '0';
            }
            if (ch == 1) {
                str = str + '1';
            }
        } while (!ht.findHuffmanCharacter(str, ch2));
        outfile.put(static_cast<char>(ch2));
        --total;
    }
    infile.close();
    outfile.close();
}

int main(int argc, char** argv)
{
    Decoder dec(argc, argv);
    try {
        dec.decode();
    } catch (std::exception& ex) {
        std::cerr << std::endl
             << "\033[1;31mError: " << ex.what() << "\033[0m"
             << std::endl;
    }
}
