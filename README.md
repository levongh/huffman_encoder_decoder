# Huffman coding
  In Computer science and information theory, a Huffman code is a particular type of optimal frefix code that is commonly used for lossless data compression. 

The output from Huffman's algorithm can be viewed as a variable length code table for encodng a source symbol (such as a character in a file). The algorithm derives this table from the estimated probability or frequency of occurrence  for each possible value of the source sybol. 

Huffman's methos can be efficiently implementedm finding code in thme linear to the number of input weights if these weights are stored.

Compression
  The technique works by creating a binary tree of nodes. these can stored in a regular array, the size of which depends on the number od symbols, n. A node can be either a leaf node or an internal node. Initially, all nodes are leaf nodes, which contain the symbol itself, the weight(frequency of appearence) of the symbol and optionally, a link to a parent node which makes it ease to read the code starting from a leaf node.


```encode -i <inital file name> -o <compressed file name>```

```decode -i <compressed file name> -o <uncompressed file name>```
