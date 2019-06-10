#pragma once

/**
 * @class Node
 * @file node.h
 * @description Node for HuffmanTree class
 * @date 07.03.2018
 * @author Levon Ghukasyan
 **/

//!@brief Node class which represents the node of the Huffman's tree
struct Node
{
public:
    unsigned char m_character;
    uint32_t m_frequency;
    Node* m_left;
    Node* m_right;

public:
    Node()
        : m_character('\0')
        , m_frequency(0)
        , m_left(nullptr)
        , m_right(nullptr)
    {
    }

    ~Node()
    {
        delete m_left;
        delete m_right;
    }
};
