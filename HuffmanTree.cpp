#include <iomanip>
#include <cctype>

#include "HuffmanTree.h"

#define WIDTH_UNIT 5

HuffmanTree::HuffmanTree()
{
    m_root = new Node();
}

HuffmanTree::~HuffmanTree()
{
    destroy(m_root);
}

void HuffmanTree::destroy(Node* node)
{
    if (nullptr != node) {
        destroy(node->m_left);
        destroy(node->m_right);
        delete node;
        node = nullptr;
    }
}

void HuffmanTree::print(std::ostream& os, Node* node, int level) const
{
    if (nullptr != node) {
        print(os, node->m_right, level + 1);
        os << std::setw(level * WIDTH_UNIT)
           << printChar(node)
           << ":"
           << node->m_frequency << std::endl;
        print(os, node->m_left, level + 1);
    }
}

void HuffmanTree::print(Node* node, int level) const
{
    if (nullptr != node) {
        print(node->m_right, level + 1);
        std::cout << std::setw(level * WIDTH_UNIT)
                  << printChar(node)
                  << ":"
                  << node->m_frequency << std::endl;
        print(node->m_left, level + 1);
    }
}

std::ostream& operator<< (std::ostream& os, const HuffmanTree& tree)
{
    tree.print(os, tree.m_root, 1);
    return os;
}

bool HuffmanTree::operator== (const HuffmanTree& tree) const
{
    return (m_root->m_frequency == tree.m_root->m_frequency);
}

bool HuffmanTree::operator!= (const HuffmanTree& tree) const
{
    return (m_root->m_frequency != tree.m_root->m_frequency);
}

bool HuffmanTree::operator< (const HuffmanTree& tree) const
{
    return (m_root->m_frequency < tree.m_root->m_frequency);
}

bool HuffmanTree::operator> (const HuffmanTree& tree) const
{
    return (m_root->m_frequency > tree.m_root->m_frequency);
}

bool HuffmanTree::operator<= (const HuffmanTree& tree) const
{
    return (m_root->m_frequency <= tree.m_root->m_frequency);
}

bool HuffmanTree::operator>= (const HuffmanTree& tree) const
{
    return (m_root->m_frequency >= tree.m_root->m_frequency);
}

void HuffmanTree::huffman(Node* node, unsigned char ch, const std::string& str, std::string& outStr) const
{
    if (nullptr != node) {
        if ((nullptr == node->m_left) &&
            (node->m_right == nullptr) &&
            (node->m_character == ch)) {
            outStr = str;
        } else {
            huffman(node->m_left, ch, str + "0", outStr);
            huffman(node->m_right, ch, str + "1", outStr);
        }
    }
}

void HuffmanTree::huffmanList(Node* node, const std::string& str) const
{
    if (nullptr != node) {
        if ((nullptr == node->m_left) && (nullptr == node->m_right)) {
            std::cout << printChar(node) << " " << str << std::endl;
        } else {
            huffmanList(node->m_left, str + "0");
            huffmanList(node->m_left, str + "1");
        }
    }
}

bool HuffmanTree::findHuffmanCharacter(const std::string& str, unsigned char& ch) const
{
    Node* curr = m_root;
    for (const auto& item : str) {
        if (item == '0') {
            curr = curr->m_left;
        }
        if (item == '1') {
            curr = curr->m_right;
        }
    }
    if (nullptr == curr->m_left && nullptr == curr->m_right) {
        ch = curr->m_character;
        return true;
    }
    return false;
}

std::string HuffmanTree::printChar(Node* node) const
{
    std::string str = std::string();
    if (nullptr == node->m_left && node->m_right) {
        unsigned char c = node->m_character;
        if (std::iscntrl(c) ||  c == 32) {
          std::string cp = std::string();
            for (int i = 0; i < 3; ++i) {
                cp += std::to_string(static_cast<int>(c % 8));
                c -= c % 8;
                c /= 8;
                str = (cp) + str;
            }
            str = '/' + str;
        } else {
            str = c;
        }
    }
    return str;
}

unsigned int HuffmanTree::getFreq() const
{
    return m_root->m_frequency;
}

void HuffmanTree::setFreq(unsigned int freq)
{
    m_root->m_frequency = freq;
}

unsigned char HuffmanTree::getChar() const
{
    return m_root->m_character;
}

void HuffmanTree::setChar(unsigned char ch)
{
    m_root->m_character = ch;
}

Node* HuffmanTree::getLeft() const
{
    return m_root->m_left;
}

void HuffmanTree::setLeft(Node* left)
{
    m_root->m_left = left;
}

Node* HuffmanTree::getRight() const
{
    return m_root->m_right;
}

void HuffmanTree::setRight(Node* right)
{
    m_root->m_right = right;
}

Node* HuffmanTree::getRoot() const
{
    return m_root;
}
