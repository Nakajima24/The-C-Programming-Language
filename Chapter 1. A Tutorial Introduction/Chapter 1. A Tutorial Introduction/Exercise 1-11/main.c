//
//  main.c
//  Chapter 1. A Tutorial Introduction
//
//  Created by Brian Chen on 10/10/2023.
//

//Exercise 1-11. How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?

//Answers summary:
//
//Semantic definition of word, some special cases:
//
//link word: "cat-walk"
//small word: a, b,c
//biiiiiig words: "a fooooooooo<40MILLIONLETTERS>ooooooo a" has 3 words
//boundary conditions:
//
//Texts with multiple spaces between words.
//Texts bigger than 2GB
//Words which contain a dash but no whitespace.
//Non-ascii words.
//Files in some different encoding (if your program supports that)
//Characters which are surrounded by whitespace but do not contain any word characters (e.g. "hello - world")
//Texts without any words
//Texts with all words on a single line
