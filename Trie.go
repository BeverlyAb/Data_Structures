package main

import (
	"fmt"
)

type TrieNode struct{
	children map[byte]TrieNode
	endOfWord bool 
}

func (tn * TrieNode)TrieNode(){
	tn.children  = make(map[byte]TrieNode)
	tn.endOfWord = false
}

type Trie struct{
	root TrieNode
}

func (t * Trie)Trie(){
	t.root.TrieNode()
}

func (t * Trie)find() bool{

	return false;
}

// func (t * Trie) insert(){

// }

func main() {
	var test Trie
	test.Trie()
	fmt.Println(test.root)
}