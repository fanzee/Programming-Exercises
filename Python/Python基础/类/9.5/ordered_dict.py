from collections import OrderedDict

vocabulary = OrderedDict({
    'compile': 'Transform computer code written in one programming language (the source language) into another'
               ' programming language (the target language). ',
    'algorithm': 'An unambiguous specification of how to solve a class of problems.',
    'bug': 'An error, flaw, failure or fault in a computer program or system that causes it to produce an'
           ' incorrect or unexpected result',
    'function': 'A relation that associates an input to a single output according to some rule',
    'index': 'A key in an associative array',
})

for key, value in vocabulary.items():
    print(key + ' : ' + value)
