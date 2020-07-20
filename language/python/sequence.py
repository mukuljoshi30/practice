#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jan  3 08:41:49 2019

@author: mukuljos
"""

#Strings

st = "10.10.101.21"
print(st.count("."))

#List
list_1 = ["1", "2", "3"]
list_1.append("4")
for i in list_1:
    print (i)
    
even = [1,2,3,4,5]
odd = [7,8,9]
numbers = even+odd
#sort doesn't create a new objet, it works on the given list
numbers.sort()
#sorted returns the new list object
print(numbers)
numbers_sort = sorted(numbers)
print(even+odd)