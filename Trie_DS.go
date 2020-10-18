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
	if index == len(word){
		return current.endOfWord
	}

	var ch byte= word[index]
	node, found := current.children[ch]
	if !found {
		return false
	} 
	return t.search(node, word, index + 1)
}

func (t * Trie) Search(word string)bool{
	return t.search(t.root, word, 0)
}

func (t * Trie)insert(current TrieNode, word string, index int){
	if index == len(word){
		current.endOfWord = true
		return
	}	
	var ch byte = word[index]
	node, found := current.children[ch]

	if !found {
		node.TrieNode()
		if index == len(word)-1{
			node.endOfWord = true
		}
		current.children[ch] = node
	}
	t.insert(node, word, index+1)
}

func (t * Trie)Insert(word string){
	t.insert(t.root, word, 0)	
}

func (t * Trie)delete(current TrieNode, word string, index int)bool{
	if index == len(word){
		if !current.endOfWord{
			return false
		}
	}
	current.endOfWord = false
	return len(current.children) == 0

	var ch byte = word[index]
	node, found := current.children[ch]
	if !found{
		return false
	}
	
	deletePot := t.delete(node, word, index+1)

	if deletePot{
		delete(current.children,ch)
		return len(current.children) == 0
	}
	return false
}

func (t * Trie)Delete(word string){
	t.delete(t.root, word, 0)
}


func main() {
	var test Trie
	test.Trie()
	test.Insert("abcde")
	test.Insert("abc")
	test.Delete("abcde")
	fmt.Println(test.Search("abcde"))
}