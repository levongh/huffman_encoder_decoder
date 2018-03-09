#pragma once

/**
 * @class HuffmanTree
 * @date 03.04.2017
 * @author Levon Ghukasyan
 */
#include <cstdint>
#include <ostream>
#include <iostream>

#include "node.h"

class HuffmanTree
{
private:
    Node* m_root;

    //! @brief destroys provided node
    void destroy(Node* node);

    //@{ printing functions
    void print(Node* node, int level) const;
    void print(std::ostream& os, Node* node, int level) const;
    //@}

    //@{ deleted constructors/assignment operators
public:
    //!@brief copy constructor
    HuffmanTree(const HuffmanTree& tree) = delete;
    //!@brief copy assignment operator
    const HuffmanTree& operator= (const HuffmanTree& tree) = delete;
    //!@brief move constructor
    HuffmanTree(HuffmanTree&& tree) = delete;
    //!@brief move assignment operator
    HuffmanTree& operator= (HuffmanTree&& tree) = delete;
    //@}

    //@{ constructor/destructor
public:
    HuffmanTree();
    ~HuffmanTree();
    //@}

    //@{ set/get functionalities
public:
    //!@brief frequency
    unsigned int getFreq() const;
    void setFreq(unsigned int freq);
    //!@brief character
    unsigned char getChar() const;
    void setChar(unsigned char ch);

    //!@brief left
    Node* getLeft() const;
    void setLeft(Node* left);
    //!@brief right 
    Node* getRight() const;
    void setRight(Node* right);

    //!@brief root
    Node* getRoot() const;
    //@}

    //@{ basic operators
public:
    friend std::ostream& operator<< (std::ostream& os, const HuffmanTree& tree);
    bool operator== (const HuffmanTree& tree) const;
    bool operator!= (const HuffmanTree& tree) const;
    bool operator<  (const HuffmanTree& tree) const;
    bool operator>  (const HuffmanTree& tree) const;
    bool operator<= (const HuffmanTree& tree) const;
    bool operator>= (const HuffmanTree& tree) const;
    //@}

    //@{ Huffman functions
public:
    /**
     * @brief find huffman string
     * @param node tree node for search start
     * @param ch a char for which need to find Huffman string equivalent
     * @param str current Huffman string according to position on the HuffmanTree
     * @param outStr string the result full Huffman string 
     **/
    void huffman(Node* node,
                 unsigned char ch,
                 const std::string& str,
                 std::string& outStr) const;
    /**
     * @brief huffman string list 
     * @param node tree node for to start the search
     * @param str current Huffman string according to position od HuffmanTree
     */
    void huffmanList(Node* node, const std::string& str) const;
    /**
     * @brief find Huffman character
     * @param str Huffman string to traverse on the HuffmanTree
     * @param ch char reference to copy founded char.
     * @return return true if a char is found else false
     **/
    bool findHuffmanCharacter(const std::string& str, unsigned char& ch) const;
    std::string printChar(Node* node) const;

};


