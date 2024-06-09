## Ged the archmage
### Statement   

Help Ged, one of the most powerful wizards on Earthsea. There, magic is based on knowing the true name of things. Ged has already learnt a long list of true names, but now he needs your help to store them efficiently, because Ged thinks that the current method used by the masters of the red-black trees is not fast enough. In particular, Ged needs to know, for every prefix of every asked word, how many true names begin with that prefix. Can you help Ged to become the master of the three-branched trees?


### Input

Input has two kind of lines: translation lines and query lines. Translation lines consist of two strings t and s, meaning that Ged has just learnt that t is the true name of s. Query lines have only one string w. All the given strings consist of lowercase letters.

### Output

For every query line, and for every position in w (starting at 0) print how many of the true names that Ged has already learnt begin with the prefix w[0..i]. Stop printing 0’s if you find that no true name has such a prefix. (That is, print at most one 0.)

Please take into account that true names can have up to 3000 characters. There will be no repeated true names, but a true name can be a prefix of another true name, and two true names can have large prefixes in common.
