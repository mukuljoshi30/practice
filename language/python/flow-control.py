#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Dec 28 10:54:52 2018

@author: mukuljos
"""

#if else control
#if:
#elif:
#else:
name = input("Please enter your name\t")
age = int(input("hoq old are you {0}?\t".format(name)))

if 18<age<31: #similar to ((18<age) and (age<30))
    print("welcome to holidays")
else:
    print("you are not eligibe for holidays")
    
#for
#continue
#break
#else else will hit if break doesn't hit 

ip_add = input("please enter the ip address\t")
segments = 0
leng = 0
   
for char in ip_add:
    if ip_add == '':
        break
    if char == '.':
        segments+= 1
        print ("this segment length is {0}".format(leng))
        leng = 0
        continue
    else:
        leng+= 1
else:
    print("You entered empty string")        
print ("this segment length is {0}".format(leng))
print ("segments = {0}".format(segments+1))    
