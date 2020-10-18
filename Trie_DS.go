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

func (t * Trie)search(current TrieNode, word string, index int) bool{
	if index == len(word) {
		return current.endOfWord
	}

	var ch byte = word[index]
	node, found := current.children[ch]
	if found {
		return t.search(node, word, index + 1)
	} else {
		return false
	}
}

func (t * Trie) Search(word string)bool{
	return t.search(t.root, word, 0)
}



// func (t * Trie) insert(){

// }

func main() {
	var test Trie
	test.Trie()
	fmt.Println(test.Search("root"))
	
}