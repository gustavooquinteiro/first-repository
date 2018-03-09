# -*- coding: utf-8 -*-
from itertools import cycle, chain, islice
import textwrap
import random
import time
import sys
import os


ok = '[' + '\033[32m' + ' OK ' + '\033[0;0m' + ']'
creating = '        Creating '
created = '  Created '

leadins = """To characterize a linguistic level L,
    On the other hand,
    This suggests that
    It appears that
    Furthermore,
    We will bring evidence in favor of the following thesis:
    To provide a constituent structure for T(Z,K),
    From C1, it follows that
    For any transformation which is sufficiently diversified in application to be of any interest,
    Analogously,
    Clearly,
    Note that
    Of course,
    Suppose, for instance, that
    Thus
    With this clarification,
    Conversely,
    We have already seen that
    By combining adjunctions and certain deformations,
    I suggested that these results would follow from the assumption that
    If the position of the trace in 99 were only relatively inaccessible to movement,
    However, this assumption is not correct, since
    Comparing these examples with their parasitic gap counterparts in (96) and (97), we see that
    In the discussion of resumptive pronouns following (81),
    So far,
    Nevertheless,
    For one thing,
    Summarizing, then, we assume that
    A consequence of the approach just outlined is that
    Presumably,
    On our assumptions,
    It may be, then, that
    It must be emphasized, once again, that
    Let us continue to suppose that
    Notice, incidentally, that """
# List of LEADINs to buy time.

subjects = """ the notion of level of grammaticalness
    a case of semigrammaticalness of a different sort
    most of the methodological work in modern linguistics
    a subset of English sentences interesting on quite independent grounds
    the natural general principle that will subsume this case
    an important property of these three types of EC
    any associated supporting element
    the appearance of parasitic gaps in domains relatively inaccessible to ordinary extraction
    the speaker-hearer's linguistic intuition
    the descriptive power of the base component
    the earlier discussion of deviance
    this analysis of a formative as a pair of sets of features
    this selectionally introduced contextual feature
    a descriptively adequate grammar
    the fundamental error of regarding functional notions as categorial
    relational information
    the systematic use of complex symbols
    the theory of syntactic features developed earlier"""
# List of SUBJECTs chosen for maximum professorial macho.

verbs = """can be defined in such a way as to impose
    delimits
    suffices to account for
    cannot be arbitrary in
    is not subject to
    does not readily tolerate
    raises serious doubts about
    is not quite equivalent to
    does not affect the structure of
    may remedy and, at the same time, eliminate
    is not to be considered in determining
    is to be regarded as
    is unspecified with respect to
    is, apparently, determined by
    is necessary to impose an interpretation on
    appears to correlate rather closely with
    is rather different from"""
#List of VERBs chosen for autorecursive obfuscation.

objects = """ problems of phonemic and morphological analysis.
    a corpus of utterance tokens upon which conformity has been defined by the paired utterance test
    the traditional practice of grammarians.
    the levels of acceptability from fairly high (e.g. (99a)) to virtual gibberish (e.g. (98d)).
    a stipulation to place the constructions into these various categories.
    a descriptive fact.
    a parasitic gap construction.
    the extended c-command discussed in connection with (34).
    the ultimate standard that determines the accuracy of any proposed grammar.
    the system of base rules exclusive of the lexicon.
    irrelevant intervening contexts in selectional rules.
    nondistinctness in the sense of distinctive feature theory.
    a general convention regarding the forms of the grammar.
    an abstract underlying order.
    an important distinction in language use.
    the requirement that branching is not tolerated within the dominance scope of a complex symbol.
    the strong generative capacity of the theory."""
# List of OBJECTs selected for profound sententiousness.


def generate_pseudo_random_text(times, line_length=72):
    parts = []
    for part in (leadins, subjects, verbs, objects):
        phraselist = list(map(str.strip, part.splitlines()))
        random.shuffle(phraselist)
        parts.append(phraselist)
    output = chain(*islice(list(zip((*parts), 0, times))))
    return textwrap.fill(' '.join(output), line_length)


def generate_random_text(filename, size):
    text = ""
    characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\n "
    i = cycle(['   ', '.', '..', '...'])
    while(len(text) != size):
            sys.stdout.write(('{}{}{}\r' .format(creating, filename, next(i))))
            sys.stdout.flush()
            text += random.choice(characters)
            time.sleep(0.1)
    sys.stdout.write(('{}{}...' .format(creating, filename)))
    return text


def convert_bytes_to(bytes, to, bsize=1024):
    array = {'K': 1, 'M': 2, 'G': 3, 'T': 4, 'P': 5, 'E': 6}
    result = float(bytes)
    for index in range(array[to]):
        result /= bsize
    return result


def generate_file(limit, typetext):
    if (typetext is 'R') or (typetext is 'r'):
        for index in range(limit):
            filename = 'example_' + str(index + 1) + '.in'
            size = random.randint(1073741844, 2059947370)
            with open(filename, 'w') as archive:
                archive.write(generate_random_text(filename, size))
            createdFilename = created + filename
            fileSize = convert_bytes_to(os.path.getsize(filename), 'G')
            print(('{} {} with {:.2f} GB' .format(ok, createdFilename, fileSize)))
    else:
        for index in range(limit):
            filename = 'example_' + str(index + 1) + '.in'
            size = random.randint(1073741844, 2059947370)
            length = random.randint(100, 599)
            with open(filename, 'w') as archive:
                archive.write(generate_pseudo_random_text(size, length))
            createdFilename = created + filename
            fileSize = convert_bytes_to(os.path.getsize(filename), 'G')
            print(('{} {} with {:.2f} GB' .format(ok, createdFilename, fileSize)))


def main():
    question = "        Choose (P) = Pseudo Random Text or (R) = Random Text: "
    typetext = str(input(question))
    try:
        answer = "        Enter the number of test files that will be created: "
        quantity = int(eval(input(answer)))
        if quantity is not 0:
            print("        Generating test files... ")
            generate_file(quantity, typetext)
        else:
            print("        Insufficient test files number")
            main()
    except NameError:
        print('Invalid type of entry')
        main()


if __name__ == '__main__':
    main()
