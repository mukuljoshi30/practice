#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Mar 11 09:56:16 2019

@author: mukuljos
"""

class Mukul(object):
    
    def __init__(self, subject, marks):
        self.subject = subject
        self.marks = marks
        
    def print_data(self):
        print(self.subject,"=",self.marks)
        
maths = Mukul("maths", 80)
print(maths.subject,"=", maths.marks)

print("{} = {}".format(maths.subject, maths.marks))

java = Mukul("java", 90)
print("{0.subject} = {0.marks} \n{1.subject} = {1.marks}".format(maths, java))
java.print_data()
Mukul.print_data(maths)

print(40*'*')
print(java.__dict__)
print(40*'*')
print(Mukul.__dict__)