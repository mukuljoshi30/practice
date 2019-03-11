#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Thu Dec 27 10:09:45 2018

@author: mukuljos
"""
print('hello world')
print (7+8)
print ('hello "mukul" joshi' + ' java')

name = input("please enter your name ")
print("\nyour name is " + name)

#print a string literals
temp = "hi I am good"
print(temp)
print(temp[3])
print(temp[-1])
print(temp[1:3])
print(temp[:3])
print(temp[1:])
print(temp[1:5:2])
print(temp[1::3])


#print string multiple times
temp1 = "hello"
print(temp *5)
print("java" *4)

#check the substring
print("hi" in temp)
print("hello" in temp)
print("hello" in "hello1")