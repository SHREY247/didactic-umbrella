/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Intuition
Trie implementation

Approach
1: Each node in the trie contains an array of 26 pointers (links) representing the alphabet (a-z) and a boolean flag to indicate if a word ends at that node.
2: containKey: Checks if there is a child node corresponding to a given character.
3: put: Sets a child node for a given character.
4: get: Returns the child node corresponding to a given character.
5: setEnd: Marks the end of a word by setting the flag to true.
6: isEnd: Checks if the node marks the end of a word.

Complexity
Time complexity:
O(length), for all three operations

Space complexity:

O(N*M), where N is number of words and M is avergae length of each word, This is because each character is stored as a node in trie

Code
*/
struct Node {
	Node *links[26];
	bool flag = false;

    //To check if trie is present or not
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}

    //Here, we are creating the reference trie for the charaacter ch
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}

	Node *get(char ch) {
		return links[ch - 'a'];
	}


    //When the string ends, we set the flag to true
	void setEnd() {
		flag = true;
	}
	
    //If flag is true, then it is the end of the string
	bool isEnd() {
		return flag;
	}
};
class Trie {
private:
	Node* root;
public:
	Trie() {
		
		root = new Node();
	}

	void insert(string word) {
	
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
            //Move to the new reference trie
			node = node->get(word[i]);
		}
		node->setEnd();
	}

	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
            //return false, if node doesn't contain word[i]
			if (!node->containKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
        //If we reach the end, and the flag is true, then return true
		return node->isEnd();
	}

	bool startsWith(string prefix) {
		Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
            //Just return false, if prefix[i] doesn't exist
			if (!node->containKey(prefix[i])) {
				return false;
			}
            //go to the next node
			node = node->get(prefix[i]);
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
