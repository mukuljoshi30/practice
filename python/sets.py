#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Feb 14 19:31:11 2019

@author: mukuljos
"""

farm_animals = {"cow", "goat", "hen"}
print(farm_animals)

for animal in farm_animals:
    print(animal)

print("="*40)

wild_animals = set(["lion", "elephant", "tiger"])
print(wild_animals)

for animal in wild_animals:
    print(animal)
    
farm_animals.add("horse")
print(farm_animals)

#sets are unordered 
'''
we can't create empty set using {} it creates empty dict
to set empty set empty_set = set()
'''

#chalange
# Create a program that takes some text and returns a list of
# all the characters in the text that are not vowels, sorted in
# alphabetical order.
#
# You can either enter the text from the keyboard or
# initialise a string variable with the string.

sampleText = "Python is a very powerful language"

vowels = frozenset("aeiou")
# vowels = {"a", "e", "i", "o", "u"}
finalSet = set(sampleText).difference(vowels)
print(finalSet)

finalList = sorted(finalSet)
print(finalList)
