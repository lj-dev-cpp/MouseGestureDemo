# MouseGestureDemo
A small experiment mixing C++, math, and a bit of machine learning

C++ Mouse Gesture Recognition Demo

Hi! This is a small side project I made while learning C++ and some basic machine learning stuff.
The goal was to recognize simple mouse gestures (like up, down, M, Z...) using a tiny neural network instead of hardcoding every shape.

What it does

You can draw with your mouse (one continuous stroke).

The program records the path, turns it into direction angles (0~360 degrees).

Then it converts those angles to a small feature vector (cos/sin pairs).

A lightweight neural net (called MLNet, written by Konstantin Boukreev back in 2001) takes those features and tells which gesture it looks like.

It’s not deep learning or anything fancy but it actually works pretty well.

