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

    void setFreq(unsigned int freq) noexcept
    {
        m_frequency = freq;
    }

    unsigned int getFreq() const noexcept
    {
        return m_frequency;
    }

    void setChar(unsigned char ch)
    {
        m_character = ch;
    }

    unsigned char getChar() const noexcept
    {
        return m_character;
    }

    void setLeft(Node* left) noexcept
    {
        m_left = left;
    }

    Node* getLeft() const noexcept
    {
        return m_left;
    }

    void setRight(Node* right) noexcept
    {
        m_right = right;
    }
    Node* getRight() const noexcept
    {
        return m_right;
    }

    ~Node()
    {
        delete m_left;
        delete m_right;
    }
};
