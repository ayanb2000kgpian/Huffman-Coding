# Huffman-Coding
Data compression and decompression program using C++.

# Introduction
This project is to design compression and decompression program using Huffman-Coding Algorithm. The idea behind Huffman Coding Algorithm is to reduce the weighted expected length of code by assigning shorter codes to most frequently used characters and longer codes to seldom used characters.

# Implementation
This program can compress and decompress text file consisting of 128 ASCII characters.

## Compression:
1. Store the input text and store the frequencies of various characters in a map.
2. Construct the priority queue and Huffman tree.
3. Encode the input text and create the Huffman Encode table(character->Huffman code).

## Decompression:
1. Decode the encoded text using the Huffman Tree.
2. Save the decoded text in desired file.

The algorithm serializes the encoded text as a binary/decimal sequence and the corresponding Huffman binary tree in order to be able to decode back the text in the future.

Here is an example of Huffman codes for each character.
![compression_and_decompression_using_huffman_coding cpp - projects - Visual Studio Code 29-06-2023 00_06_32](https://github.com/ayanb2000kgpian/Huffman-Coding/assets/138036625/4cf52ba6-87e2-41fe-8d8f-db2f07857d2f)

Text encoded in binary format, then decoded and compression ratio:
![compression_and_decompression_using_huffman_coding cpp - projects - Visual Studio Code 29-06-2023 00_07_58](https://github.com/ayanb2000kgpian/Huffman-Coding/assets/138036625/617dfa13-548d-4f36-b4d4-61c82069a50a)

It can be seen that the string is compressed to about 6.8% of the original string.

