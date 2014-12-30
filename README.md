Lexical-Analysis
================
Author: Robin Li
------------------------------------------------------------------------
Background:
Language processing programs (such as compilers, interpreters, and assemblers) examine the source code being processed. First it is brokenup into component pieces (lexical analysis). Then verified that those pieces form legal statements (syntax analysis). Then generate an equivalent version of the program that can be executed by the compiler(code generation). The Lexical Analysis Scanner part of processing tokens can be described as a Finite-State Machine. The scanner reads the input character by character, determining what type of element each represents and converts the information into a token to be handled by the syntax analyzer (parser) to examine input elements and verify their legality.
------------------------------------------------------------------------
Overview:
This program implements a Lexical Analysis Scanner to read a subset of the
C language: identifiers, decimal integers, octal integers, block-style comments, and basic arithmetic operators. The scanner is implemented using a transition matrix. 
