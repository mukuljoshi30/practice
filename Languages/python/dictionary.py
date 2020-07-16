#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Feb 12 20:04:15 2019

@author: mukuljos
"""

fruit = {"orange": "a sweet, orange, citrus fruit",
         "apple": "good for making cider",
         "lemon": "a sour, yellow citrus fruit",
         "grape": "a small, sweet fruit growing in bunches",
         "lime": "a sour, green citrus fruit"}

# print(fruit)
# print(fruit["lemon"])
# fruit["pear"] = "an odd shaped apple"
# print(fruit)
# fruit["lime"] = "great with tequila"
# print(fruit)
# # del fruit["lemon"]
# # fruit.clear()
# # print(fruit)
# print(fruit["tomato"])
'''
print(fruit)
while True:
    dict_key = input("Please enter a fruit: ")
    if dict_key == "quit":
        break
    if dict_key in fruit:
        description = fruit.get(dict_key)
        print(description)
    else:
        print("we don't have a " + dict_key)
'''
print('='*40)
for item in fruit:
    print(fruit[item])
    
print('='*40)
#ordered_keys = list(fruit.keys())
#ordered_keys.sort()

ordered_keys = sorted(list(fruit.keys()))
for f in ordered_keys:
    print(f +"-"+fruit[f])
print('='*40)
#without key it's less efficient
for f in fruit.values():
    print(f)
#Dict to ptuple
print('='*40)   
f_tuple = fruit.items()
print(f_tuple)

#tuple to Dict
f_dict = dict(f_tuple)

print('='*40) 
letters = 'adasdasdf'
newsrting = ''
newstring = ", ".join(letters)
print(newstring)


print('='*40) 
#Combining two dict
fruit = {"orange": "a sweet, orange, citrus fruit",
         "apple": "good for making cider",
         "lemon": "a sour, yellow citrus fruit",
         "grape": "a small, sweet fruit growing in bunches",
         "lime": "a sour, green citrus fruit"}
veg = {"tomato":"red color veg",
       "potato":"has lot of fat"}
#don't return anything
veg.update(fruit)
print(veg)


veg_copy = veg.copy()
print(veg_copy)