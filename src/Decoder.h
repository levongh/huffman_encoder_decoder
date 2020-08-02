#pragma once

/**
 * @class Decoder
 * @file Decoder.h 
 * @description Huffman Decoder class
 * @date 07.03.2018
 * @author Levon Ghukasyan
 **/

#include "CoderBase.h"

class Decoder : public CoderBase
{
public:
    //!@brief constructor
    Decoder(int argc, char** argv);

    //@{ deleted constructors and assignment operators
public:
    Decoder() = delete;
    Decoder(const Decoder& other) = delete;
    Decoder& operator= (const Decoder& other) = delete;
    Decoder(Decoder&& other) = delete;
    Decoder& operator= (Decoder&& other) = delete;
    //@}

public:
     //!@breif decodes input file in write the results to output file
    void decode() const;

private:
    /**
     * @brief returns the Huffman character from input file stream
     * @param infile input file stream
     * @return Huffman character
     */
    unsigned char readHuffmanChar(std::ifstream& infile) const;

private:
    std::string m_inputFileName;
    std::string m_outputFileName;
};
