cmake_minimum_required(VERSION 3.9)
project(analiseSentimento)

set(CMAKE_CXX_STANDARD 11)

add_executable(analiseSentimento main.cpp TrieNode.cpp TrieNode.h Vocabulario.cpp Vocabulario.h Palavra.cpp Palavra.h)