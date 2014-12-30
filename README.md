#Lexical Analysis

Language processing programs (such as compilers, interpreters, and assemblers) examine the source code being processed. First it is brokenup into component pieces (lexical analysis). Then verified that those pieces form legal statements (syntax analysis). Then generate an equivalent version of the program that can be executed by the compiler(code generation). The Lexical Analysis Scanner part of processing tokens can be described as a Finite-State Machine. The scanner reads the input character by character, determining what type of element each represents and converts the information into a token to be handled by the syntax analyzer (parser) to examine input elements and verify their legality.

## Installation

1. Download MinGW to obtain the GNU Compiler Collection(GNU) for compiling C programs. 
2. Download zip file.

## Usage

1. Use header.mak to generate the make file and use the make file to create the executable. 
2. Type "./tokenize tm.1" to create a transition matrix. (Top row are the classes, d = discard, s = save, the number is the next state. 
3. Type an identifier, decimal integer, octal integer, block-style comment, or arithmetic operator. 
4. The output will show the transition it went through in the transition matrix. 

## History

Project 1 of CSCI243 - Mechanics of Programming 

## Credits

Author: Robin Li

## License

The MIT License (MIT)

Copyright (c) [2014] [Robin Li]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
