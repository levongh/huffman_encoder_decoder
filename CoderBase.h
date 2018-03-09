#pragma once

/**
 * @class CoderBase
 * @file CoderBase.h
 * @date 07.03.2018
 * @author Levon Ghukasyan
 */

#include <string>
#include <fstream>

inline void help()
{
    std::cout << "Usage: \n"
              << "\t-i input file name\n"
              << "\t-o output file name"
              << std::endl;
}


/**
 * @breif this class defined to incapsulate Decoder/Encoder common interfaces
 */
class CoderBase
{
    //@{ deleted constructors and assignment operators
public:
    CoderBase() = delete;
    CoderBase(const CoderBase& other) = delete;
    CoderBase& operator= (const CoderBase& other) = delete;
    CoderBase(CoderBase&& other) = delete;
    CoderBase& operator= (CoderBase&& other) = delete;
    //@}

public:
    //!@constructor
    CoderBase(int argc, char** argv)
    {
        for (int i = 1; i < argc; ++i) {
            if ((strcmp("-i", argv[i]) == 0) && (i + 1 < argc)) {
                m_inputFileName = argv[++i];
            } else if ((strcmp("-o", argv[i]) == 0) && (i + 1 < argc)) {
                m_outputFileName = argv[++i];
            }
        }
    }

    //!brief checks file names
    bool check() const
    {
        if (m_inputFileName.empty() || m_outputFileName.empty()) {
            return false;
        }
        return true;
    }

    void openFileStreams(std::ifstream& infile, std::ofstream& outfile) const
    {
        if (!check()) {
            help();
            throw std::runtime_error("Input and output file are requiered");
        }
        infile = std::ifstream(m_inputFileName.c_str(), std::ios::in | std::ios::binary);
        if (!infile) {
            throw std::runtime_error(std::string("The input file \"") +
                                     m_inputFileName +
                                     std::string("\" could not be opened"));
        }
        if (std::ifstream(m_outputFileName.c_str())) {
            throw std::runtime_error(std::string("The output file \"") +
                                     m_outputFileName +
                                     std::string("\" already exist"));
        }
        outfile = std::ofstream(m_outputFileName.c_str(), std::ios::out | std::ios::binary);
        if (!outfile) {
            throw std::runtime_error(std::string("The output file \"") +
                                     m_inputFileName +
                                     std::string("\"could not be opened"));
        }
    }

protected:
    std::string m_inputFileName;
    std::string m_outputFileName;
};
