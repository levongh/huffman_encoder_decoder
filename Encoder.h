#pragma once

/**
 * @class Encoder
 * @file Encoder.h 
 * @description Huffman Encoder class
 * @date 07.03.2018
 * @author Levon Ghukasyan
 **/

#include "CoderBase.h"

class Encoder : public CoderBase
{
public:
    //!@brief constructor
    Encoder(int argc, char** argv);

    //@{ deleted constructors and assignment operators
public:
    Encoder() = delete;
    Encoder(const Encoder& other) = delete;
    Encoder& operator= (const Encoder& other) = delete;
    Encoder(Encoder&& other) = delete;
    Encoder& operator= (Encoder&& other) = delete;
    //@}

public:
     //!@breif decodes input file in write the results to output file
    void encode() const;

private:
    /**
     * @brief writes the Huffman character to output file stream
     * @param i character which should be writen
     * @param outfile output file stream
     */
    void writeHuffmanChar(unsigned char i, std::ofstream& outfile) const;

private:
    std::string m_inputFileName;
    std::string m_outputFileName;
};
