#include <string>
#include <cstring>
#include <queue>

#include "HuffmanTree.h"
#include "Encoder.h"

Encoder::Encoder(int argc, char** argv)
    : CoderBase(argc, argv)
{
}

void Encoder::writeHuffmanChar(unsigned char i, std::ofstream& outfile) const
{
    static int pos = 0;
    static unsigned char c = '\0';
    if (i < 2) {
        if (i == 1) {
            c = c | (i << (7 - pos));
        } else {
            c = c & static_cast<unsigned char>(255 - (1 << (7 - pos)));
        }
        ++pos;
        pos %= 8;
        if (pos == 0) {
            outfile.put(c);
            c = '\0';
        }
    } else {
        outfile.put(c);
    }
}

void Encoder::encode() const
{
    std::ifstream infile;
    std::ofstream outfile;
    openFileStreams(infile, outfile);

    unsigned int freq[256];
    std::fill(freq, freq + 256, 0);
    char c;
    unsigned char ch;
    while (infile.get(c)) {
        ch = c;
        ++freq[ch];
    }
    infile.clear();
    infile.seekg(0);

    std::queue<Node*> nodes;

    for (int idx = 0; idx < 256; ++idx) {
        outfile.put(static_cast<unsigned char>(freq[idx] >> 24));
        outfile.put(static_cast<unsigned char>((freq[idx] >> 16) % 256));
        outfile.put(static_cast<unsigned char>((freq[idx] >> 8) % 256));
        outfile.put(static_cast<unsigned char>(freq[idx] % 256));
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
    std::string huffmanTable[256];
    unsigned char uc;
    for (unsigned short us = 0; us < 256; ++us) {
        huffmanTable[us] = "";
        uc = static_cast<unsigned char>(us);
        ht.huffman(ht.getRoot(), uc, "", huffmanTable[us]);
    }
    unsigned char ch2 = ' ';
    while (infile.get(c)) {
        ch = c;
        for (unsigned i = 0; i < huffmanTable[ch].size(); ++i) {
            if (huffmanTable[ch].at(i) == '0') {
                ch2 = 0;
            }
            if (huffmanTable[ch].at(i) == '1') {
                ch2 = 1;
            }
            writeHuffmanChar(ch2, outfile);
        }
    }
    ch2 = 2;
    writeHuffmanChar(ch2, outfile);
    infile.close();
    outfile.close();
}


int main(int argc, char** argv)
{
    Encoder enc(argc, argv);
    try {
        enc.encode();
    } catch (std::exception& ex) {
        std::cerr << std::endl
             << "\033[1;31mError: " << ex.what() << "\033[0m"
             << std::endl;
    }
}
