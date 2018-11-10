vocabulary = {
    'compile': 'Transform computer code written in one programming language (the source language) into another'
               ' programming language (the target language). ',
    'algorithm': 'An unambiguous specification of how to solve a class of problems.',
    'bug': 'An error, flaw, failure or fault in a computer program or system that causes it to produce an'
           ' incorrect or unexpected result',
    'function': 'A relation that associates an input to a single output according to some rule',
    'index': 'A key in an associative array',
}

vocabulary['batch'] = 'A command to queue jobs for later execution'
vocabulary['bus'] = 'Public communication trunk for transmitting information between various functional components' \
                    ' of a computer'
vocabulary['class'] = 'A fundamental concept of object-oriented programming'
vocabulary['html'] = 'Standard markup language for creating web pages and web applications'
vocabulary['sql'] = 'A domain-specific language used in programming and designed for managing data held in a ' \
                    'relational database management system '

for k, v in vocabulary.items():
    print(k + " : " + v)
