#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

typedef struct Node *TST;

struct Node
{
  char c;
  Node *left, *mid, *right;
  bool isEndOfString;
  Node(char ch) : c(ch), left(nullptr), mid(nullptr), right(nullptr), isEndOfString(false) {}
};

class TernarySearchTree
{
private:
  Node *root;
  unordered_set<string> stringSet;

  Node *insert(Node *t, const string &s, int i)
  {
    if (t == nullptr)
      t = new Node(s[i]);

    if (s[i] < t->c)
      t->left = insert(t->left, s, i);
    else if (s[i] > t->c)
      t->right = insert(t->right, s, i);
    else
    {
      if (i + 1 < s.size())
        t->mid = insert(t->mid, s, i + 1);
      else
        t->isEndOfString = true;
    }
    return t;
  }

  Node *erase(Node *t, const string &s, int i)
  {
    if (t == nullptr)
      return nullptr;

    if (s[i] < t->c)
      t->left = erase(t->left, s, i);
    else if (s[i] > t->c)
      t->right = erase(t->right, s, i);
    else
    {
      if (i + 1 < s.size())
        t->mid = erase(t->mid, s, i + 1);
      else
        t->isEndOfString = false;
    }
    return t;
  }

  bool search(Node *t, const string &s, int i)
  {
    if (t == nullptr)
      return false;

    if (s[i] < t->c)
      return search(t->left, s, i);
    else if (s[i] > t->c)
      return search(t->right, s, i);
    else
    {
      if (i + 1 == s.size())
        return t->isEndOfString;
      return search(t->mid, s, i + 1);
    }
  }

  void clear(Node *&t)
  {
    if (t == nullptr)
      return;
    clear(t->left);
    clear(t->mid);
    clear(t->right);
    delete t;
    t = nullptr;
  }

  bool startsWith(const string &word, const string &prefix)
  {
    if (prefix.size() > word.size())
    {
      return false;
    }
    return equal(prefix.begin(), prefix.end(), word.begin());
  }

public:
  TernarySearchTree() : root(nullptr) {}

  ~TernarySearchTree()
  {
    clear(root);
    stringSet.clear();
  }

  void insert(const string &s)
  {
    if (stringSet.find(s) == stringSet.end())
    {
      root = insert(root, s, 0);
      stringSet.insert(s);
    }
  }

  void erase(const string &s)
  {
    if (stringSet.find(s) != stringSet.end())
    {
      root = erase(root, s, 0);
      stringSet.erase(s);
    }
  }

  void reset()
  {
    clear(root);
    stringSet.clear();
  }

  vector<int> countPrefixes(const string &prefix)
  {
    vector<int> counts;
    int i = 0;
    while (i < prefix.size() and (i == 0 or counts[i - 1] > 0))
    {
      counts.push_back(0);
      for (const auto &word : stringSet)
      {
        if (startsWith(word, prefix.substr(0, i + 1)))
        {
          counts[i]++;
        }
      }
      i++;
    }
    return counts;
  }
};

int main()
{
  TernarySearchTree tst;
  string line;

  while (getline(cin, line))
  {
    istringstream iss(line);
    string word1, word2;

    // Attempt to read two words from the line
    if (iss >> word1 >> word2)
    {
      tst.insert(word1);
      tst.erase(word2);
    }
    else
    {
      // Clear the stream and read the single word again
      iss.clear();
      iss.str(line);
      iss >> word1;
      vector<int> counts = tst.countPrefixes(word1);
      cout << word1 << ":";
      for (int i = 0; i < counts.size(); i++)
      {
        cout << " " << counts[i];
      }
      cout << endl;
    }
  }
}
