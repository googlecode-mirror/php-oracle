# thanks to http://aima.cs.berkeley.edu/
import sys
from utils import *

def Rules(**rules):
	for (lhs, rhs) in rules.items():
		rules[lhs] = [alt.strip().split() for alt in rhs.split('|')]
	return rules

def Lexicon(**rules):
	for (lhs, rhs) in rules.items():
		rules[lhs] = [word.strip() for word in rhs.split('|')]
	return rules

class Grammar:
	def __init__(self, name, rules, lexicon):
		"A grammar has a set of rules and a lexicon."
		update(self, name=name, rules=rules, lexicon=lexicon)
		self.categories = DefaultDict([])
		for lhs in lexicon:
			for word in lexicon[lhs]:
				self.categories[word].append(lhs)
	def rewrites_for(self, cat):
		"Return a sequence of possible rhs's that cat can be rewritten as."
		return self.rules.get(cat, ())
	def isa(self, word, cat):
		"Return True iff word is of category cat"
		return cat in self.categories[word]
	def __repr__(self):
		return '<Grammar %s>' % self.name

class Definition:
	def __init__(self, grammar, trace=False):
		update(self, grammar=grammar, trace=trace)

	def parses(self, words, S='S'):
		if isinstance(words, str):
			words = words.split()
		self.parse(words, S)
		return [[i, j, S, found, []]
				for (i, j, lhs, found, expects) in self.chart[len(words)]
				# print j == len(words)
				if i == 0 and lhs == S and expects == []]




	def parse(self, words, S='S'):
		"""Parse a list of words; according to the grammar.
		Leave results in the chart."""
		self.chart = [[] for i in range(len(words)+1)]
		self.add_edge([0, 0, 'S_', [], [S]])
		for i in range(len(words)):
			self.scanner(i, words[i])
		return self.chart
	def add_edge(self, edge):
		start, end, lhs, found, expects = edge
		if edge not in self.chart[end]:
			self.chart[end].append(edge)
			if self.trace:
				print '%10s: added %s' % (caller(2), edge)
			if not expects:
				self.extender(edge)
			else:
				self.predictor(edge)
	def scanner(self, j, word):
		for (i, j, A, alpha, Bb) in self.chart[j]:
			if Bb and self.grammar.isa(word, Bb[0]):
				self.add_edge([i, j+1, A, alpha + [(Bb[0], word)], Bb[1:]])
	def predictor(self, (i, j, A, alpha, Bb)):
		B = Bb[0]
		if B in self.grammar.rules:
			for rhs in self.grammar.rewrites_for(B):
				self.add_edge([j, j, B, [], rhs])
	def extender(self, edge):
		(j, k, B, _, _) = edge
		for (i, j, A, alpha, B1b) in self.chart[j]:
			if B1b and B == B1b[0]:
				self.add_edge([i, k, A, alpha + [edge], B1b[1:]])


E0 = Grammar('E0',
	Rules(
		S = 'NP VP | S Conjunction S | VP PP',
		NP = 'Pronoun | Noun | Article Noun | Adjective Noun | NP PP | NP RelClause | Name Noun',
		VP = 'Verb | VP NP | VP Adjective | VP PP | VP Adverb',
		PP = 'Preposition NP | Preposition VP',
		RelClause = 'That VP'
	),

	Lexicon(
		Noun = "data | input | output | privilege | context | header | user | sink | file | path",
		Verb = "is | go | write | print | access | use",
		Adjective = "validated | unvalidated | asynchronous",
		Adverb = "asynchronously",
		Pronoun = "me | you | i | it",
		Name = "ssl | ajax | html | database | http | sql | ldap",
		Article = "the | a | an",
		Preposition = "to | in | on",
		Conjunction = "and | or | but | not",
		That = "that"
	))

def contains_list(o):
	if not isinstance(o,list):
		return False
	for l in o:
		if isinstance(l,list):
			return True
	return False

def recursive_print(data, _add = ""):
	s = _add
	for k in data:
		if not contains_list(k):
			s += str(k)
		else:
			if isinstance(k,list):
				recursive_print(k, _add + " ")
			else:
				s += str(k)
	if len(s) > 0:
		print s

def convert_grammar_xml(data, _add = ""):
	"""
		Convert the output trees into XML format
		<token />
	"""
	for k in data:
		if isinstance(k, list):
			print _add,"<token>"
			convert_grammar_xml(k, _add + " ")
			print _add,"</token>"
		else:
			if isinstance(k, tuple):
				print _add,"<content type='%s'>%s</content>" % (k[0],k[1])
			else:
				a = 0
				#print _add,"<information>%s</information>"  %  (str(k))






d = Definition(E0, False)
print "# source definition:"
xss = "unvalidated input go to sink in HTML context".lower()
sql = "unvalidated data go to database sink".lower()
path = "use unvalidated path to access a file".lower()


s = path
#print s
out = d.parses(s)
#print "out", out
xml = convert_grammar_xml(out)


#print "# parse tree:"
#print len(out), "possiblities"
#for o in out:
	#print "##"
	#recursive_print(o)

